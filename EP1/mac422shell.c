#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_LENGTH 1024
#define DELIMS " \t\r\n"
#define ARGS_SIZE 64

char** shell_split_cmd(char *cmd_line) {
    int position = 0; /* array index */
    char **params = malloc(ARGS_SIZE * sizeof(char*));

    while(cmd_line != NULL) {
        params[position] = cmd_line;
        position++;

        cmd_line = strtok(NULL, DELIMS); 
    }
    params[position] = NULL;

    return params;
}

void shell_exec_cmd(char *cmd_line) {
    char **params = shell_split_cmd(cmd_line);

    if (strcmp(params[0], "protegepracaramba") == 0) {
        if (params[1] != NULL) {
            
        }
    }    
}

int main() {

}