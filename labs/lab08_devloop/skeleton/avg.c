/*
 * avg.c — SKELETON: a program with one deliberate bug. Find it with gdb.
 *
 * Chapter 08, core lab L08 — QNX: Zero to Hero
 *
 * The bug is in sum_readings(): the loop condition is `i <= count`, so it
 * reads one element past the end of the array. This is undefined behaviour
 * that USUALLY looks fine, which is exactly why it is worth finding with a
 * debugger rather than by reading.
 *
 * -Wall -Wextra does NOT catch it: the compiler cannot know count's value at
 * the call site.
 *
 * YOUR TASK: do not read ahead. Build it, deploy it, run it, and find the
 * bug with the debugger (Chapter 08 Lab 08.1, steps 1-3). Only then fix it.
 * The corrected version is in ../solution/avg.c.
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

    /* BUG: `i <= count` reads r[count], which is past the end.
     * Valid indices are 0 .. count-1, so this must be `i < count`.
     * Fix it only AFTER you have found it in gdb -- that is the exercise. */
    for (int i = 0; i <= count; i++)
        total += r[i];

    return total;
}

int main(void)
{
    int readings[4] = { 10, 20, 30, 40 };
    int n = 4;

    printf("sum     = %d\n", sum_readings(readings, n));
    printf("average = %d\n", sum_readings(readings, n) / n);

    /*
     * The correct average is 25. If you see 25, the garbage read from r[4]
     * happened to be small. Run it several times, and on the target as well
     * as the host -- undefined behaviour is not required to be consistent.
     */
    return 0;
}
