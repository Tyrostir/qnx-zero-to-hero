/*
 * jitter.c — SKELETON.  Fill in the four TODOs.
 *
 * Chapter 01, Lab 01.2 — QNX: Zero to Hero
 *
 * Goal: ask to sleep for exactly INTERVAL_US microseconds, N times, and measure
 * how long each sleep ACTUALLY took. The spread is jitter.
 *
 * The complete version is in ../solution/jitter.c — but try the TODOs first.
 * Licence: MIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N            10000
#define INTERVAL_US   1000
#define NSEC_PER_USEC 1000L
#define NSEC_PER_SEC  1000000000L

static long elapsed_us(const struct timespec *a, const struct timespec *b)
{
    /* TODO 1: return the number of microseconds between *a and *b.
     *         Remember that tv_sec and tv_nsec are separate fields, so you
     *         must combine both -- subtracting tv_nsec alone is wrong whenever
     *         the interval crosses a second boundary.               */
    (void)a; (void)b;
    return 0;
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

    for (i = 0; i < N; i++) {
        /* TODO 2: read the monotonic clock into `before`.
         *         Which clock, and why not the other one?           */

        nanosleep(&req, NULL);

        /* TODO 3: read the monotonic clock into `after`, then store the
         *         measured interval in sample[i] and add it to `total`. */
    }

    qsort(sample, N, sizeof sample[0], cmp_long);

    /* TODO 4: print min, mean, p50, p99, max and jitter.
     *         The array is sorted, so min is sample[0], max is sample[N-1],
     *         and p99 is sample[(N*99)/100]. Mean needs `total`.
     *         Which of these would you put in a safety case?         */

    printf("TODO: print the statistics\n");
    return 0;
}
