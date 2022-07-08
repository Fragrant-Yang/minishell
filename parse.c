#include "parse.h"
#include "externs.h"

#include <stdio.h>
#include <string.h>

void shell_loop()
{
    while(1) {
        printf("[minishell]$ ");
        memset(cmdline, 0, sizeof(cmdline));
        if(read_command() == -1)
            break;
        parse_command();
        execute_command();
    }
    printf("\nexit\n");
}

int read_command()
{
    if(fgets(cmdline, sizeof(cmdline-1), stdin) == NULL) 
        return -1;
    return 0;
}

int parse_command()
{

    return 0;
}

int execute_command()
{

    return 0;
}