#include <unistd.h>
#include <stdio.h>

unsigned int snooze(unsigned int secs){
  unsigned int timeleft = sleep(secs);
  printf("Slept for %d of %d secs\n", secs - timeleft, secs);
  return timeleft;
}


int main(int argc, char*argv[]){
  snooze(5);
  return 0;
}