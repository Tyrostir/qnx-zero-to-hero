/*
 * jitter.c — measure the difference between a requested sleep and a real one.
 *
 * Chapter 01, Lab 01.2 — QNX: Zero to Hero
 *
 * The idea: ask to sleep for exactly INTERVAL_US microseconds, N times, and
 * measure how long each sleep ACTUALLY took. The spread between the shortest
 * and the longest is jitter -- the quantity Chapter 01 section 3.3 is about.
 *
 * Nothing here is QNX-specific: it is plain POSIX and would build on Linux too.
 * That is deliberate. Run it on both and compare the tails.
 *
 * Licence: MIT (see labs/LICENSE)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N            10000    /* number of samples                      */
#define INTERVAL_US   1000    /* requested sleep, microseconds (1 ms)   */
#define NSEC_PER_USEC 1000L
#define NSEC_PER_SEC  1000000000L

/* Elapsed microseconds between two timespecs. */
static long elapsed_us(const struct timespec *a, const struct timespec *b)
{
    long sec  = (long)(b->tv_sec  - a->tv_sec);
    long nsec = (long)(b->tv_nsec - a->tv_nsec);
    return (sec * NSEC_PER_SEC + nsec) / NSEC_PER_USEC;
}

static int cmp_long(const void *x, const void *y)
{
    long a = *(const long *)x, b = *(const long *)y;
    return (a > b) - (a < b);
}

int main(void)
{
    static long sample[N];
    struct timespec req = { 0, INTERVAL_US * NSEC_PER_USEC };
    struct timespec before, after;
    long long total = 0;
    int i;

    /*
     * CLOCK_MONOTONIC, not CLOCK_REALTIME: monotonic time cannot jump
     * backwards when someone adjusts the wall clock or NTP steps it.
     * Never measure a duration with a clock that can be set.
     */
    for (i = 0; i < N; i++) {
        if (clock_gettime(CLOCK_MONOTONIC, &before) != 0) {
            perror("clock_gettime");
            return 1;
        }

        nanosleep(&req, NULL);

        if (clock_gettime(CLOCK_MONOTONIC, &after) != 0) {
            perror("clock_gettime");
            return 1;
        }

        sample[i] = elapsed_us(&before, &after);
        total += sample[i];
    }

    /* Sort only AFTER measuring -- never do work inside the measured region. */
    qsort(sample, N, sizeof sample[0], cmp_long);

    printf("samples : %d   requested interval : %d us\n", N, INTERVAL_US);
    printf("min     : %5ld us\n", sample[0]);
    printf("mean    : %5lld us\n", total / N);
    printf("p50     : %5ld us\n", sample[N / 2]);
    printf("p99     : %5ld us\n", sample[(N * 99) / 100]);
    printf("max     : %5ld us\n", sample[N - 1]);
    printf("jitter  : %5ld us  (max - min)\n", sample[N - 1] - sample[0]);

    /*
     * The point of the exercise: mean is a throughput statistic, max is the
     * only one a deadline can be built on.
     */
    if (sample[N - 1] > 2 * INTERVAL_US)
        printf("\nNote: worst case is more than 2x the request. "
               "See Chapter 01 section 2.3.\n");

    return 0;
}
