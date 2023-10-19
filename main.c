#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *args[2];
    int status;
    pid_t pid;
    
    while (1) {
               printf("simple_shell> ");
        
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
        
            printf("\n");
            break;
        }
        
        input[strcspn(input, "\n")] = 0;

        pid = fork();
        
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }
        
        if (pid == 0) {
                   args[0] = input;
            args[1] = NULL;
            
                    if (execvp(input, args) == -1) {
                perror("Execution failed");
                exit(1);
            }
        } else {
      

            waitpid(pid, &status, 0);
            
            if (WIFEXITED(status)) {
                printf("Child exited with status %d\n", WEXITSTATUS(status));
            }
        }
    }
    
    return 0;
}

