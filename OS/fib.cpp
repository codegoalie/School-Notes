#include <iostream>
#include <string>

// Required by for routine
#include <sys/types.h>
#include <unistd.h>

#include <stdlib.h>   // Declaration for exit()

using namespace std;

int fib(int num);

int main(int argc, char** argv)
{
  cout << fib(atoi(argv[1])) << "\n";
  return 0;
}

int fib(int num)
{
  if(num > 0)
  {
    pid_t pID = fork();
    if (pID == 0)                // child
    {
      // Code only executed by child process

      return num + fib(num-2);

    }
    else if (pID < 0)            // failed to fork
    {
      cerr << "Failed to fork" << endl;
      exit(1);
      // Throw exception
    }
    else                                   // parent
    {
      // Code only executed by parent process
      wait();
      return 0;

    }
  }
  else
    return 0;
}
