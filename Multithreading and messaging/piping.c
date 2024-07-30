#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
  int fd[2];
  pid_t childpid;

  // Create a pipe
  pipe(fd);

  // Fork a child process
  childpid = fork();
  if (childpid == -1) {
    perror("fork");
    exit(1);
  }

  // Parent process
  if (childpid > 0) {
    // Close the read end of the pipe
    close(fd[0]);

    // Write to the write end of the pipe
    char *message = "Hello, world!\n";
    write(fd[1], message, strlen(message));

    // Close the write end of the pipe
    close(fd[1]);

    // Wait for the child process to finish
    wait(NULL);
  }

  // Child process
  else {
    // Close the write end of the pipe
    close(fd[1]);

    // Read from the read end of the pipe
    char buffer[1024];
    int bytes_read = read(fd[0], buffer, sizeof(buffer));

    // Print the message
    printf("%s", buffer);

    // Close the read end of the pipe
    close(fd[0]);
  }

  return 0;
}