#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int accounts[5] = { 10000, 10000, 10000, 10000, 10000 };
pthread_mutex_t mutex;
struct data {
    int a1;
    int a2;
    int money;
};
void* cost(void* arg)
{
    if (accounts[a1] >= money) {
        sleep(1);
        if (pthread mutex_lock(&work_mutex) != 0) {
            perror("lock faild");
            exit(1);
        }
        accounts[]
    }
}
int main(void)
{

    return 0;
}
