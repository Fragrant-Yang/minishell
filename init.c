#include "init.h"
#include <stdio.h>
#include <signal.h>

void sigint_handler(int sig);

void setup() {
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, SIG_IGN);
}

void sigint_handler(int sig)
{
    printf("\n[minishell]$ ");
    fflush(stdout);
}