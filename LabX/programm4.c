#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {
    pid_t pid;
    int fd;

    // Open a file for writing
    fd = open("process_pids.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    // Fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork failed");
        close(fd);
        return 1;
    }

    if (pid == 0) {
        // Child process
        char buffer[100];
        snprintf(buffer, sizeof(buffer), "Child PID: %d\n", getpid());
        write(fd, buffer, strlen(buffer));  // Write to the file
    } else {
        // Parent process
        char buffer[100];
        snprintf(buffer, sizeof(buffer), "Parent PID: %d\n", getpid());
        write(fd, buffer, strlen(buffer));  // Write to the file

        // Wait for the child to finish
        wait(NULL);
    }

    // Close the file
    close(fd);

    return 0;
}
