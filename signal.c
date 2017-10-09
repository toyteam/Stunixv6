#include "signal.h"


void signal(int sig, void (*func)(int))
{
    if(sig<=0||sig>64) return;
    proc->signal=proc->signal|(1>>sig);
    return;
}

void do_signal()
{
    for(int i=0;i<SIGMAX;++i)
    {
        if(proc->signal&(1<<i)==(1<<i))
        {
            
        }
    }
    return;
}