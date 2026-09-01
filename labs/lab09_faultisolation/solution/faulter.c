/*
 * faulter.c — dereference NULL on purpose, and observe that the system survives.
 *
 * Chapter 09, Lab 09.2 — QNX: Zero to Hero
 *
 * This program deliberately crashes. That is the entire point: run it, then
 * look at the system with pidin and see that NOTHING ELSE CHANGED.
 *
 * On a monolithic kernel the equivalent bug IN A DRIVER ends the machine. Here
 * it ends one process, and the only trace is one fewer line in pidin.
 *
 * Licence: MIT (see labs/LICENSE)
 */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int *p = NULL;

    printf("faulter: pid %d, about to dereference NULL\n", getpid());

    /*
     * fflush() matters here, and it is not a detail.
     *
     * stdout is line-buffered on a terminal but BLOCK-buffered when piped or
     * redirected. A process that dies with data still in its buffer never
     * prints it -- so without this, the message above can vanish and you are
     * left debugging a program that appears to produce no output at all.
     *
     * fflush(FILE *) is ISO C, <stdio.h>. Returns 0, or EOF on error.
     */
    fflush(stdout);

    /*
     * Virtual address 0 is deliberately left unmapped by the system, so this
     * write raises a page fault rather than corrupting whatever happened to
     * live there. procnto classifies the fault, terminates this process with
     * SIGSEGV, frees its memory, closes its connections, and wakes any client
     * blocked on it with an error.
     *
     * See Chapter 09 section 5.2 for the nine steps.
     */
    *p = 42;

    printf("faulter: never reached\n");
    return 0;
}
