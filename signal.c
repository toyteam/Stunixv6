#include "signal.h"


void signal(int sig, void (*func)(int))
{
    if(sig<=0||sig>64) return;
    proc->signal=proc->signal|(1>>sig);
    return;
}

void do_signal()
{
    return;
}