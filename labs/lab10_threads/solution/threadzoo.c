/*
 * threadzoo.c -- Lab 10.1, QNX: Zero to Hero, Chapter 10
 *
 * One process. Five threads. Each thread parks itself in a DIFFERENT blocking
 * state, so that `pidin -p threadzoo` on the target shows a menagerie:
 *
 *      NANOSLEEP   the sleeper, and the mutex holder
 *      CONDVAR     the condvar waiter
 *      MUTEX       the contender, blocked on a mutex it will never get
 *      JOIN        main, waiting for a thread that never returns
 *
 * The point of the lab is NOT the program. It is the `pidin` listing:
 * one pid, five tids, five states, one address space.
 *
 * Build:  make            (needs `source ~/qnx800/qnxsdp-env.sh` first)
 * Run:    make TGT=<ip> run,  then `pidin -p threadzoo` in another session.
 * Stop:   Ctrl-C, or `slay threadzoo` from the other session.
 */

#include <stdio.h>      /* printf, fflush                                    */
#include <stdlib.h>     /* EXIT_FAILURE                                      */
#include <string.h>     /* strerror                                          */
#include <unistd.h>     /* getpid                                            */
#include <pthread.h>    /* everything pthread_*                              */
#include <time.h>       /* nanosleep, struct timespec                        */

/* ------------------------------------------------------------------------ *
 * Shared state.  It is `static` at file scope, which means it lives in the
 * process's data segment -- and every thread sees THE SAME OBJECT.  That is
 * the definition of a thread: same address space, different stack.
 * ------------------------------------------------------------------------ */

static pthread_mutex_t held    = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t cv_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  cv      = PTHREAD_COND_INITIALIZER;

/* A counter every thread increments, to prove they share memory. */
static int arrivals = 0;

/* Sleep for `secs` seconds without using sleep(), so the state is NANOSLEEP
 * rather than anything sleep() might be implemented with. */
static void park(int secs)
{
    struct timespec ts;
    ts.tv_sec  = secs;
    ts.tv_nsec = 0;
    nanosleep(&ts, NULL);
}

static void announce(const char *role)
{
    /* pthread_self() returns this thread's own id.  On QNX that id is the
     * same small integer `pidin` prints in its `tid` column -- checking that
     * is one of the lab's questions, so we print it as a number. */
    printf("  tid %-3d  %s\n", (int)pthread_self(), role);
    fflush(stdout);
    arrivals++;              /* deliberately unsynchronised; see the README */
}

/* ---- thread 2: sleeps forever ------------------------------- NANOSLEEP - */
static void *sleeper(void *unused)
{
    (void)unused;
    announce("sleeper      -> expect NANOSLEEP");
    for (;;)
        park(3600);
    return NULL;
}

/* ---- thread 3: waits on a condition that never happens -------- CONDVAR - */
static void *waiter(void *unused)
{
    (void)unused;
    announce("cond waiter  -> expect CONDVAR");
    pthread_mutex_lock(&cv_lock);
    for (;;)
        pthread_cond_wait(&cv, &cv_lock);   /* releases cv_lock while waiting */
    /* not reached */
    return NULL;
}

/* ---- thread 4: takes `held` and never gives it back ---------- NANOSLEEP - */
static void *holder(void *unused)
{
    (void)unused;
    announce("mutex holder -> expect NANOSLEEP (and it owns `held`)");
    pthread_mutex_lock(&held);
    for (;;)
        park(3600);                          /* holding the mutex the whole time */
    return NULL;
}

/* ---- thread 5: wants `held`, will never get it ------------------ MUTEX - */
static void *contender(void *unused)
{
    (void)unused;
    announce("contender    -> expect MUTEX");
    park(1);                                 /* let `holder` win the race */
    pthread_mutex_lock(&held);               /* blocks here, permanently */
    printf("  contender got the mutex -- this line should never print\n");
    fflush(stdout);
    return NULL;
}

int main(void)
{
    pthread_t sleeper_t, waiter_t, holder_t, contender_t;
    int rc;

    printf("threadzoo: pid %d\n", (int)getpid());
    printf("  tid %-3d  main         -> expect JOIN once the others are up\n",
           (int)pthread_self());
    fflush(stdout);

    /* pthread_create() starts a thread INSIDE THIS PROCESS.  No new address
     * space, no new pid.  Underneath it is the ThreadCreate() kernel call. */
    rc = pthread_create(&sleeper_t,   NULL, sleeper,   NULL);
    if (rc != 0) { fprintf(stderr, "pthread_create: %s\n", strerror(rc)); return EXIT_FAILURE; }

    rc = pthread_create(&waiter_t,    NULL, waiter,    NULL);
    if (rc != 0) { fprintf(stderr, "pthread_create: %s\n", strerror(rc)); return EXIT_FAILURE; }

    rc = pthread_create(&holder_t,    NULL, holder,    NULL);
    if (rc != 0) { fprintf(stderr, "pthread_create: %s\n", strerror(rc)); return EXIT_FAILURE; }

    rc = pthread_create(&contender_t, NULL, contender, NULL);
    if (rc != 0) { fprintf(stderr, "pthread_create: %s\n", strerror(rc)); return EXIT_FAILURE; }

    park(2);                                  /* let everyone announce itself */
    printf("\nall threads up. arrivals = %d\n", arrivals);
    printf("now run  `pidin -p threadzoo`  in another session.\n");
    printf("stop me with Ctrl-C, or `slay threadzoo`.\n");
    fflush(stdout);

    /* main now blocks in JOIN, waiting for a thread that never returns. */
    pthread_join(sleeper_t, NULL);

    return 0;                                 /* never reached */
}
