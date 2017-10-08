
enum Sig{
    SIGALRM,
    SIGHUP,
    SIGINT,
    SIGKILL
};

#define SIGRTMIN 0
#define SIGRTMAX 32
#define SIGMAX 64

typedef struct{
    unsigned long sig[2];
}sigset_t;

typedef struct{

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
};

struct sigaction{
    void(*sa_handler)();
    sigset_t sa_mask;
};

struct signhand_struct{
    struct sigaction action[SIGMAX];
};

void signal(int sig, void (*func)(int));

void do_signal();