/*
 * threadzoo.c -- Lab 10.1 SKELETON, QNX: Zero to Hero, Chapter 10
 *
 * Fill in the four TODOs.  When it works, one process will show FIVE threads
 * in `pidin -p threadzoo`, each in a different blocking state.
 *
 * The reference implementation is in ../solution/threadzoo.c -- but try it
 * first.  Every TODO is two or three lines.
 *
 * Build:  make SRC=skeleton/threadzoo.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

static pthread_mutex_t held    = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t cv_lock = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t  cv      = PTHREAD_COND_INITIALIZER;

static int arrivals = 0;

static void park(int secs)
{
    struct timespec ts;
    ts.tv_sec  = secs;
    ts.tv_nsec = 0;
    nanosleep(&ts, NULL);
}

static void announce(const char *role)
{
    /* TODO 1 -- print this thread's own id.
     *
     * pthread_self() takes no arguments and returns the calling thread's id.
     * On QNX that value is the same small integer `pidin` shows in its `tid`
     * column, so print it as an int:
     *
     *     printf("  tid %-3d  %s\n", (int)pthread_self(), role);
     *
     * Remember fflush(stdout) -- Chapter 09 §5.1 explains why.
     */

    arrivals++;
}

static void *sleeper(void *unused)
{
    (void)unused;
    announce("sleeper      -> expect NANOSLEEP");
    for (;;)
        park(3600);
    return NULL;
}

static void *waiter(void *unused)
{
    (void)unused;
    announce("cond waiter  -> expect CONDVAR");

    /* TODO 2 -- park this thread on the condition variable, forever.
     *
     * pthread_cond_wait(&cv, &cv_lock) requires that cv_lock is already
     * held; it releases it while waiting and re-acquires it on return.
     * Lock cv_lock first, then loop on pthread_cond_wait.
     */

    return NULL;
}

static void *holder(void *unused)
{
    (void)unused;
    announce("mutex holder -> expect NANOSLEEP (and it owns `held`)");

    /* TODO 3 -- lock `held` and never unlock it, then sleep forever. */

    return NULL;
}

static void *contender(void *unused)
{
    (void)unused;
    announce("contender    -> expect MUTEX");
    park(1);                       /* let `holder` win the race */

    /* TODO 4 -- try to lock `held`.  This thread will block here for good;
     * that is the whole point.  What state does `pidin` show for it? */

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

    rc = pthread_create(&sleeper_t,   NULL, sleeper,   NULL);
    if (rc != 0) { fprintf(stderr, "pthread_create: %s\n", strerror(rc)); return EXIT_FAILURE; }

    rc = pthread_create(&waiter_t,    NULL, waiter,    NULL);
    if (rc != 0) { fprintf(stderr, "pthread_create: %s\n", strerror(rc)); return EXIT_FAILURE; }

    rc = pthread_create(&holder_t,    NULL, holder,    NULL);
    if (rc != 0) { fprintf(stderr, "pthread_create: %s\n", strerror(rc)); return EXIT_FAILURE; }

    rc = pthread_create(&contender_t, NULL, contender, NULL);
    if (rc != 0) { fprintf(stderr, "pthread_create: %s\n", strerror(rc)); return EXIT_FAILURE; }

    park(2);
    printf("\nall threads up. arrivals = %d\n", arrivals);
    printf("now run  `pidin -p threadzoo`  in another session.\n");
    fflush(stdout);

    pthread_join(sleeper_t, NULL);

    return 0;
}
