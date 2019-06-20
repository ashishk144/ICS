#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

unsigned int snooze(unsigned int secs){
    unsigned int timeleft = sleep(secs);
    printf("Slept for %d of %d secs\n", secs - timeleft, secs);
    return timeleft;
}

void handler(int sig)
{
    return;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Need at least 1 argv.\n");
        exit(0);
    }
    
    if (signal(SIGINT, handler) == SIG_ERR)
        printf("Signal Error\n");
    
    snooze(atoi(argv[1]));
    
    return 0;
}