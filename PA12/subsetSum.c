#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include "pa12.h"

#define SUCCESS 0
#define FAILURE -1


typedef struct Threadtask{
  int * subset;
  int N;
  int len;
  int start;
  int end;
  int * counter;
  pthread_mutex_t *  mutex_o;
}Task;

/*
* Write a parallel C program that returns the answer for the following problem:
* Given a nonempty set S, with elements {a1, a2, a3, ...}, and a integer N, 
* find the number of nonempty subsets of S, such that the sum of all elements 
* in this subset equals to N.
*
* Arguments:
*	intset - pointer to an array of a integer set
*	length - size (length) of the integer set
*	N - target sum value
*	numThread - number of threads 
* Return value:
*	numOfSolutions - Number of nonempty subsets in which the subsetSum value 
*	matches with N. This variable should be protected as the critical 
*	sections by using mutex objects.
*
* Hint: The total number of possible subsets is (2^(length)-1). You may use
* 	math library function 'pow()' to assign the index for each thread.
* 	pthread.h and math.h are already included in this file.
*/
/*void condition_wait(void * set)
{
  Task * subs = (Task *)set;
  pthread_mutex_lock(&subs -> mutex_o);
  if(!pthread_cond_wait(&subs -> condwait, &subs -> mutex_o)
     checkSubset(subs);
     pthread_mutex_unloc(&subs -> mutex_o);
     }*/
int countsumOf(int * set, int len, int index)
{
  if(len > (pow(2, len) - 1))
    {
      printf("This program cannot handle more than %f length of set", (pow(2, len) - 1));
    }
  int sum = 0;
  int i;
  for(i = 0; i < len; i ++)
    {
      if(((index >> i) & 0x0001) == 1)
	{
	  sum += set[i];
	}
    }
  return sum;
}
  

void * countSubsets(void * Thread)
{
  Task * thtask = (Task *)Thread;
  if(thtask != NULL){
    int i;
    for(i = thtask -> start; i <= thtask -> end; i++)
      {
	if(countsumOf(thtask -> subset, thtask  -> len, i) ==  thtask -> N)
	  {
	    pthread_mutex_lock(thtask -> mutex_o);
	    *(thtask -> counter) += 1;
	    pthread_mutex_unlock(thtask -> mutex_o);
	  }
      }
    // pthread_exit(NULL);
    return (void *)thtask;
  }
  return NULL;
 } 

void assignTasks(Task * Thread, int Thread_n, int * set, int N, int len, int numThread, int * counter, pthread_mutex_t * mutex_o)
{
  int task_size = pow(2,len) / numThread;
  Thread -> subset = set;
  Thread -> N  = N;
  Thread -> len = len;
  Thread -> start = task_size * (Thread_n);
  if(!(Thread_n == numThread - 1))
    Thread -> end = Thread -> start + task_size - 1;
  else
    Thread -> end = (int)pow(2,len) - 1;
  if(Thread_n == 0)
    Thread -> start = 1;
  Thread -> counter = counter;
  Thread -> mutex_o = mutex_o;
}


int subsetSum(int * intset, int length, int N, int numThread)
{ 
  int counter = 0;
  pthread_mutex_t mutex_o = PTHREAD_MUTEX_INITIALIZER;
  pthread_t p_threads[numThread];
  int thread_id[numThread];
  /*
  Task * subs = malloc(sizeof(Task));
  subs -> subsets = malloc(sizeof(int *) * pow(2,length));
  subs -> subsets[0] = malloc(sizeof(int) * length);
  subs -> count = 0;
  subs -> pthread_mutex_t mutex_o = PTHREAD_MUTEX_INITIALIZER;
  subs -> condwait = PTHREAD_COND_INITIALIZER;
  int thread_id[numThread];
  pthread p_threads[numThread];
  int setcount = 0;*/
  int i,j;
  j = 0;
  Task * thTasks[numThread];
  for(i = 0; i < numThread; i++)
    {
      thTasks[i] = malloc(sizeof(Task));
      assignTasks(thTasks[i], i,intset, N,length, numThread, &counter, &mutex_o);
    }
  while(j < numThread)
    {
      thread_id[j] = pthread_create(&p_threads[j], NULL, countSubsets, (void *)thTasks[j]);
      j++;
    }
  for(i = 0; i < numThread; i++)
    {
      pthread_join(p_threads[i], NULL);
    }
  /*
  j = (int)(pow(2, length)) % numThread;
  if(j)
  {
  for(i = 1; i < pow(2,length); i++)
	{
	  if(countsumOf(intset, length, i) == N)
	    {
	      pthread_mutex_lock(&mutex_o);
	      counter++;
	      pthread_mutex_unlock(&mutex_o);
	    }
	}
	}*/
  pthread_mutex_destroy(&mutex_o);
  for(i = 0; i < numThread; i++)
    {
      free(thTasks[i]);
    }
  return counter;
}
