#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *args[2];
char status_msg[100];
int len, status;
pid_t pid;
const char *prompt;
    
    while (1) {
          prompt = "simple_shell> ";
        write(STDOUT_FILENO, prompt, strlen(prompt));
        
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
                    write(STDOUT_FILENO, "\n", 1);
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
                len = snprintf(status_msg, sizeof(status_msg), "Child exited with status %d\n", WEXITSTATUS(status));
                write(STDOUT_FILENO, status_msg, len);
            }
        }
    }
    
    return 0;
}

