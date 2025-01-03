#ifndef __LIBERRNUM_H__
#define __LIBERRNUM_H__


typedef int err_t;

enum {
    ERR_ARG = 1,
    ERR_ALLOC,

    // FILES
    ERR_FOPEN,
    ERR_FCLOSE,

    // SOCKETS
    ERR_NEW_SCK,
    ERR_CLOSE_SCK,
    ERR_INET_PTON,
    ERR_CONN,
    ERR_BIND,
    ERR_LISTEN,
    ERR_ACCEPT_CONN,
    ERR_SHUTDOWN_SCK,

    // DATA
    ERR_READ,
    ERR_WRT,

    // THREADS
    ERR_NEW_TH
};


// String with the program name to print before the error message
// Initialized to NULL and, if no argument is passed, the program
// name isn't printed
extern char *errnum_program_name;


// Prints error msg (some events requiere another argument)
// Returns the error event
err_t errnum(err_t _ErrorEvent, ...);


#endif
