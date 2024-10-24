#include <stdio.h>
#include <errno.h>
#include <stdarg.h>
#include <string.h>

#include "errnum.h"


char *errnum_program_name = NULL;


int errnum(err_t e, ...) {
    int errno_val = errno;

    va_list arg;
    va_start(arg, e);


    if(errnum_program_name != NULL) fprintf(stderr, "%s: ", errnum_program_name);

    switch (e) {
        case ERR_ARG:
            fprintf(stderr, "Usage: %s", va_arg(arg, const char *));
            break;

        case ERR_ALLOC:
            fprintf(stderr, "There was a problem with the memory while running the code");
            break;

        // FILES
        case ERR_FOPEN:
            fprintf(stderr, "Couldn't access the file '%s'", va_arg(arg, const char *));
            break;

        case ERR_FCLOSE:
            fprintf(stderr, "Couldn't close the file '%s'", va_arg(arg, const char *));
            break;

        // SOCKETS
        case ERR_NEW_SCK:
            fprintf(stderr, "Couldn't create a communication line (socket)");
            break;

        case ERR_CLOSE_SCK:
            fprintf(stderr, "Couldn't finish the communication line (socket)");
            break;

        case ERR_INET_PTON:
            fprintf(
                stderr,
                "Couldn't convert the address '%s' into a network address",
                va_arg(arg, const char *)
            );

            break;

        case ERR_CONN:
            fprintf(stderr, "Couldn't connect to the server");
            break;

        case ERR_BIND:
            fprintf(stderr, "Couldn't assign the address to the communication line (socket)");
            break;

        case ERR_LISTEN:
            fprintf(stderr, "Couldn't listen for incoming connections");
            break;

        case ERR_ACCEPT_CONN:
            fprintf(stderr, "Couldn't accept incoming connections");
            break;

        // DATA
        case ERR_READ:
            fprintf(stderr, "Problem while reading the data");
            break;

        case ERR_WRT:
            fprintf(stderr, "Problem while writting the data");
            break;

        // TERMINAL
        case ERR_TCGET:
            fprintf(stderr, "Couldn't get the terminal attributes");
            break;

        case ERR_TCSET:
            fprintf(stderr, "Couldn't modify the terminal attributes");
            break;
    }

    if(errno_val > 0) fprintf(stderr, "%s (Errno::%d)", strerror(errno_val), errno_val);


    va_end(arg);
    return (errno_val) ? errno_val : -1;
}
