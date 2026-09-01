/*
 * stacksize.c -- Lab 10.3, QNX: Zero to Hero, Chapter 10
 *
 * Replace a guess with a number: how big is a QNX 8 thread's default stack?
 *
 * Chapter 10 §3.2 says the stack is what a thread costs, and then declines to
 * say how much, because the course does not know. This program knows.
 *
 * Build:  make SRC=solution/stacksize.c BIN=stacksize
 */

#include <stdio.h>      /* printf                       */
#include <string.h>     /* strerror                     */
#include <pthread.h>    /* pthread_attr_*               */
#include <limits.h>     /* PTHREAD_STACK_MIN            */

int main(void)
{
    pthread_attr_t a;
    size_t sz = 0;
    int rc;

    /* pthread_attr_init() fills the object with the SYSTEM DEFAULTS -- which
     * is exactly what we want to read back out of it. */
    rc = pthread_attr_init(&a);
    if (rc != 0) {
        printf("pthread_attr_init: %s\n", strerror(rc));
        return 1;
    }

    rc = pthread_attr_getstacksize(&a, &sz);
    if (rc != 0) {
        printf("pthread_attr_getstacksize: %s\n", strerror(rc));
        return 1;
    }

    /* %zu is the printf conversion for size_t. Not %d, not %lu -- size_t is
     * a different width on different targets, and %zu is the portable one. */
    printf("default thread stack : %zu bytes (%zu KB)\n", sz, sz / 1024);

#ifdef PTHREAD_STACK_MIN
    printf("PTHREAD_STACK_MIN    : %d bytes (%d KB)\n",
           (int)PTHREAD_STACK_MIN, (int)PTHREAD_STACK_MIN / 1024);
#else
    printf("PTHREAD_STACK_MIN    : not defined in this toolchain\n");
#endif

    printf("\n200 threads at the default would cost %zu KB of stack alone.\n",
           (sz / 1024) * 200);

    pthread_attr_destroy(&a);
    return 0;
}
