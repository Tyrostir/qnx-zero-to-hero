/*
 * forktest.c -- Lab 10, 💥 Break It.  QNX: Zero to Hero, Chapter 10
 *
 * ONE QUESTION:  what does fork() do in a process that has more than one
 * thread?
 *
 * The course states that on QNX you should use posix_spawn() rather than
 * fork(), and that fork() from a multi-threaded process is at best
 * restricted.  The course has NOT run this.  This program finds out.
 *
 * It forks TWICE:
 *   1. while single-threaded  -- the easy case, expected to work
 *   2. after creating a thread -- the interesting case
 *
 * Whatever happens, the program reports it and exits cleanly.  There is no
 * "correct" output; the output IS the result.
 *
 * Build:  make SRC=solution/forktest.c BIN=forktest
 */

#include <stdio.h>      /* printf, fflush            */
#include <stdlib.h>     /* exit, EXIT_SUCCESS        */
#include <string.h>     /* strerror                  */
#include <errno.h>      /* errno                     */
#include <unistd.h>     /* fork, getpid, _exit       */
#include <pthread.h>    /* pthread_create            */
#include <sys/wait.h>   /* waitpid                   */
#include <time.h>       /* nanosleep                 */
#include <spawn.h>      /* posix_spawn               */

extern char **environ;  /* the process environment; posix_spawn wants it */

static void park_ms(long ms)
{
    struct timespec ts;
    ts.tv_sec  = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}

/* A thread that does nothing but exist. Its existence is the experiment. */
static void *idler(void *unused)
{
    (void)unused;
    for (;;)
        park_ms(1000);
    return NULL;
}

/* fork(), report exactly what came back, and reap any child. */
static void try_fork(const char *label)
{
    pid_t kid;

    printf("--- %s ---\n", label);
    fflush(stdout);                 /* flush BEFORE forking: an unflushed
                                       buffer would be duplicated and printed
                                       twice, once by each process. */

    errno = 0;
    kid = fork();

    if (kid < 0) {
        printf("  fork() FAILED: returned %d, errno %d (%s)\n",
               (int)kid, errno, strerror(errno));
        fflush(stdout);
        return;
    }

    if (kid == 0) {
        /* Child.  POSIX says that after fork() in a multi-threaded process
         * only async-signal-safe functions may be called -- printf is not
         * one of them.  We use write(2) instead, which is. */
        const char msg[] = "  child: I exist.\n";
        ssize_t n = write(STDOUT_FILENO, msg, sizeof(msg) - 1);
        (void)n;
        _exit(0);                   /* _exit, not exit: do not flush the
                                       parent's buffers a second time. */
    }

    printf("  fork() returned child pid %d\n", (int)kid);
    fflush(stdout);

    int status = 0;
    if (waitpid(kid, &status, 0) < 0)
        printf("  waitpid: %s\n", strerror(errno));
    else
        printf("  child reaped, status %d\n", status);
    fflush(stdout);
}

int main(void)
{
    pthread_t t;
    int rc;

    printf("forktest: pid %d, single-threaded so far\n", (int)getpid());
    fflush(stdout);

    /* ---- experiment 1: fork from a single-threaded process ---- */
    try_fork("fork() with ONE thread");

    /* ---- now become multi-threaded ---- */
    rc = pthread_create(&t, NULL, idler, NULL);
    if (rc != 0) {
        printf("pthread_create: %s\n", strerror(rc));
        return EXIT_FAILURE;
    }
    pthread_detach(t);              /* we never join it; let it clean itself up */
    park_ms(200);                   /* make sure it is really running */

    printf("\nnow multi-threaded (main + idler)\n");
    fflush(stdout);

    /* ---- experiment 2: fork from a multi-threaded process ---- */
    try_fork("fork() with TWO threads");

    /* ---- experiment 3: the QNX-preferred way, still multi-threaded ---- */
    printf("--- posix_spawn() with TWO threads ---\n");
    fflush(stdout);
    {
        pid_t     kid = -1;
        char     *argv[] = { "echo", "  spawned child: I exist.", NULL };
        int       err;

        err = posix_spawn(&kid, "/proc/boot/echo", NULL, NULL, argv, environ);
        if (err != 0) {
            /* Not on the boot image?  Try the usual path instead. */
            argv[0] = "echo";
            err = posix_spawnp(&kid, "echo", NULL, NULL, argv, environ);
        }

        if (err != 0) {
            printf("  posix_spawn FAILED: %d (%s)\n", err, strerror(err));
        } else {
            int status = 0;
            printf("  posix_spawn returned child pid %d\n", (int)kid);
            fflush(stdout);
            waitpid(kid, &status, 0);
            printf("  child reaped, status %d\n", status);
        }
        fflush(stdout);
    }

    printf("\ndone. Report all three results.\n");
    return EXIT_SUCCESS;
}
