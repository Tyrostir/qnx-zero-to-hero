/*
 * avg.c — SOLUTION: the corrected version.
 *
 * Chapter 08, core lab L08 — QNX: Zero to Hero
 *
 * The bug in ../skeleton/avg.c was in sum_readings(): the loop condition was
 * `i <= count`, reading one element past the end of the array. Valid indices
 * are 0 .. count-1.
 *
 * Note that -Wall -Wextra did NOT catch it: the compiler cannot know count's
 * value at the call site. Only running it under a debugger and printing r[4]
 * makes it obvious.
 *
 * Licence: MIT (see labs/LICENSE)
 */

#include <stdio.h>

/*
 * Sum `count` readings from the array `r`.
 *
 * r     : pointer to the first element (read-only, hence const)
 * count : number of valid elements
 * returns: the sum
 */
static int sum_readings(const int *r, int count)
{
    int total = 0;

    /* FIXED: `i < count`. Valid indices are 0 .. count-1. */
    for (int i = 0; i < count; i++)
        total += r[i];

    return total;
}

int main(void)
{
    int readings[4] = { 10, 20, 30, 40 };
    int n = 4;

    printf("sum     = %d\n", sum_readings(readings, n));
    printf("average = %d\n", sum_readings(readings, n) / n);

    /* Now prints sum = 100, average = 25 -- every time, on every machine. */
    return 0;
}
