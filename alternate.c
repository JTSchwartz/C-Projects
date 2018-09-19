#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int pingpong(int process, int string, int count) {	
   fprintf(stderr, "PPID: %d, PID: %d, %s\n", getppid(), getpid(), (string == 0) ? "pong" : "ping");

   process = fork();

   if(process == 0 && count < 18) pingpong(getpid(), abs(string - 1), ++count);

   return 0;
}

int main() {

   int pid = fork();

   if(pid != 0 ) {
      fprintf(stderr, "PPID: %d, PID: %d, %s\n", getppid(), getpid(), "ping");
   } else { 
      pingpong(0, 0, 0); 
   }

   return 0;
}
