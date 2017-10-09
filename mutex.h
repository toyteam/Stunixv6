

struct mutex
{
    atomic_t count;
    spinlock waitlock;

};