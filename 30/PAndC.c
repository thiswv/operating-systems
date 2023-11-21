#include <stdio.h>
#include <pthread.h>
#include <assert.h>
#define MAX 100

int buffer[MAX];
int fill_ptr = 0;
int use_ptr = 0;
int count = 0;

void Pthread_cond_signal(pthread_cond_t *cond) {
    int result = pthread_cond_signal(cond);
    assert(result != 0);
}

void Pthread_cond_wait(pthread_cond_wait *wait, pthread_mutex_t *mutex)
{
  int result = pthread_cond_wait(wait, mutex);
  assert(result != 0);
}


void put(int value) 
{
  buffer[fill_ptr] = value;
  fill_ptr = (fill_ptr + 1) % MAX;
  count ++;
}

int get()
{
  int tmp = buffer[use_ptr];
  use_ptr = (use_ptr + 1) % MAX;
  count --;
  return tmp;
}

pthread_cond_t empty, fill;
pthread_mutex_t mutex;

void *producer(void *arg)
{
  for (int i = 0; i < loops; i ++) {
    
  }
}