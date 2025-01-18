#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

// Signal handler function for the child process
void sigusr1_handler(int sig) {
	printf("Child received SIGUSR1 (signal %d).\n",sig);
}

int main() {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    if(pid==0){
        //Child process
        if(signal(SIGUSR1,sigusr1_handler) == SIG_ERR){
            perror("signal");
            exit(EXIT_FAILURE);
        }
        printf("Child with ID : %d waiting for SIGURS1 signal from father..\n",getpid());
        while(1){
            pause(); // Wait for signals
        }
    }
    else{
        //Parent process
        sleep(3);
        printf("Parent sending SIGURS1 to child.\n");
        if(kill(pid,SIGUSR1) == -1){
            perror("kill");
            exit(EXIT_FAILURE);
        }
        sleep(1);
        if(kill(pid,SIGTERM) == -1){
            perror("kill");
            exit(EXIT_FAILURE);
        }
        wait(NULL);
        printf("Child process terminated.\n");
    }
}
