#include "init.h"
#include "externs.h"
#include "def.h"
#include <stdio.h>
#include <string.h>
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

void init()
{
    memset(cmdline, 0, sizeof(cmdline));
    memset(argline, 0, sizeof(argline));
    cmdptr = cmdline;
    argptr = argline;

    memset(cmd.args, 0, sizeof(cmd.args));
    cmd_count = 0;
}