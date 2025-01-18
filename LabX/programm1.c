#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	
	for(int i=0; i<3; i++){
		pid = fork(); // Create child process

		if(pid < 0){
			// Fork failed
            		perror("fork failed");
            		return 1;
		}
		
		if (pid == 0) {
           		// Child process
            		printf("Child PID: %d\n", getpid());
            		return 0; // Exit the child process
        	}
	}		
	// Parent process prints its own PID
   	printf("Parent PID: %d\n", getpid());	
	// Wait for all child processes to finish before exiting
    	for (int i = 0; i < 3; i++) {
        	wait(NULL);
    	}	
	return 0;

}
