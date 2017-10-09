#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "spinlock.h"
#include "signal.h"
#include "proc.h"


int
sys_alarm(void)
{
  int ticks;
  void(*handler)();

  if(argint(0,&ticks)<0)
    return -1;

  if(argptr(1,(char**)&handler,1)<0)
    return -1;


  return fork();
}