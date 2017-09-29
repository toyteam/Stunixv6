
#include "spinlock.h"



enum Sig{
    SIGALRM,
    SIGHUP,
    SIGINT,
    SIGKILL
}

typedef struct{
    unsigned long sig[2];
}sigset_t;

struct signal_struct{
    volatile int count;
    struct spinlock siglock;
}



void signal(int sig, void (*func)(int));

