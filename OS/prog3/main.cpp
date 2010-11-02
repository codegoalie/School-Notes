/*
 * Chris Marshall
 * 11.1.2010
 * Operating Systems
 * Programming Assignment 3
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <semaphore.h>

int buffer[10];
int buffer_count =0;
bool producer_running;

int main()
{
  sem_t sem;            // Initialize semaphore
  sem_init(&sem, 1, 1);

  // Initialize shared memory space
  const int share_size = sizeof(int) * (2 + 1024 * 1024);
  int segment_id = shmget(IPC_PRIVATE, share_size, (IPC_CREAT | IPC_EXCL | 0400));

  int *buffer_count = (int *) shmat(segment_id, NULL, 0);
  int *producer_running = buffer_count +1;
  int *buffer = buffer_count+2;
  *producer_running = 1;

    pid_t pID = fork();
    if(pID == 0)
    {
      // child process (consumer)
      std::ofstream child_log;
      child_log.open("child_log.txt", std::ios::app);
      child_log << "\n\nStarted Child Process\n"; 

      bool done_work = false;
      if(true)
      {
        while(true) //producer_running && !done_work)  // while the producer is still working and there are fibs to do
        {
          while(buffer_count <= 0) { child_log << "waiting for ints"; } // wait until there are ints to fib
          sem_wait(&sem); // wait for semaphore
          int num = buffer[buffer_count--]; // push int from buffer
          sem_post(&sem); // release semaphore
          int fib = 0;
          for(int i=1; i <=num; ++i) // calculate fibonacci number
          {
            fib += i;
          }

          child_log << "Got " << num << " and calc fib of " << fib << std::endl;
          done_work = true;
        }
      }
      else
      {
        child_log << "Producer wasn't started\n";
      }

      child_log << "End of Child\n";
      child_log.close();
    }
    else if(pID < 0)
    {
        std::cout << "Failed to Fork";
        return 0;
    }
    else
    {
      // parent process (producer)
      std::ofstream parent_log;
      parent_log.open("parent_log.txt", std::ios::app);
      parent_log << "\n\nStarted Parent Process\n"; 

      producer_running = 1;

      srand(time(NULL));

      for(int i=0; i < 20; ++i) // limit to 20 writes to buffer (it's gotta end sometime)
      {
        parent_log << buffer_count << std::endl;
        while(buffer_count >= 10) { parent_log << "waiting for space\n"; } // wait for space in buffer to open up
        //while(rand() % 100 > 90) {}  // wait until you pick a number greater than 90 but less than 100 (arbitrary time)
        sem_wait(&sem); // wait for semphore
        buffer[buffer_count++] = rand() % 100; // push random less than 100 to buffer
        sem_post(&sem); // release semaphore
      }
      
      producer_running = 0;
      parent_log << "end of parent\n";
      parent_log.close();
    }

    return 1;
}
