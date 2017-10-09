
enum Sig{
    SIGALRM,
    SIGHUP,
    SIGINT,
    SIGKILL
};

enum SiCode{
    SI_USER,
    SI_KERNEL,
    SI_QUEUE,
    SI_TIMER,
    SI_ASYNCIO,
    SI_TKILL
};

#define SIGRTMIN 0
#define SIGRTMAX 32
#define SIGMAX 64

typedef struct{
    unsigned long sig[2];
}sigset_t;

typedef struct{
    uint si_signo;
    uint si_errno;
    uint si_code;
}siginfo_t;

struct sigqueue{
    struct sigqueue * next;
    siginfo_t info;
};

struct sigpending{
    struct sigqueue *head, *tail;
    sigset_t signal;
};


struct signal_struct{
    volatile int count;
    struct spinlock siglock;
    struct sigaction action[SIGMAX];
};

struct sigaction{
    void(*sa_handler)();
    sigset_t sa_mask;
    uint sa_flag;
};

void signal(int sig, void (*func)(int));

void sigaddset(sigset_t *set,uint nsig);

void sigdelset(sigset_t *set,uint nsig);

void sigaddsetmask(sigset_t *set,uint mask);

void signal_pending(uint pid);

void do_signal();