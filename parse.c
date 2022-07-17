#include "parse.h"
#include "externs.h"
#include "def.h"
#include "init.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void print_command();

void shell_loop()
{
    while(1) {
        printf("[minishell]$ ");
        init();
        if(read_command() == -1)
            break;
        parse_command();
        print_command();
        execute_command();
    }
    printf("\nexit\n");
}

/**
 * @brief 从标准输入读取命令 并存入 cmdline数组 中
 * 
 * @return 成功返回0 失败返回 -1
 */
int read_command()
{
    if(fgets(cmdline, sizeof(cmdline)-1, stdin) == NULL) 
        return -1;
    return 0;
}

/**
 * @brief 解析命令 将命令解析为 命令和参数的样式。
 * 
 * @return 成功返回0 失败返回 -1
 */
int parse_command()
{
    int i = 0;
    int inword = 0;
    /* 将 ls -l 解析为 ls\0-l\0 */
    while(*cmdptr) {
        /* 跳过左空格 */
        while (*cmdptr == ' ' ||
            *cmdptr == '\t')
            cmdptr++;

        cmd.args[i] = argptr;
        while (*cmdptr != '\0' &&
            *cmdptr != ' ' &&
            *cmdptr != '\t' &&
            *cmdptr != '\n' &&
            *cmdptr != '|' &&
            *cmdptr != '>' &&
            *cmdptr != '<' &&
            *cmdptr != '&') 
        {
            *argptr++ = *cmdptr++;
            inword = 1;
        }
        *argptr++ = '\0';
        // printf("i= %d, %s ", i, cmd.args[i]);
        switch (*cmdptr)
        {
        case ' ':
        case '\t':
            i++;
            break;
        case '|':
        case '<':
        case '>':
        case '&':
        case '\n':
            if (!inword) 
                cmd.args[i] = NULL;
            return 0;
        default:
            break;
        }
    }

    return 0;
}

void print_command()
{
    int i = 0;
    // printf("cmd_count = %d\n", cmd_count);
    while (cmd.args[i]) {
        printf("%s ", cmd.args[i]);
        ++i;
    }
    printf("\n");
}

/**
 * @brief 执行命令
 * 
 * @return 成功返回0，失败返回-1
 */
int execute_command()
{
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        perror("fork error");
        exit(1);
    }
    
    if (pid > 0) {
        while( wait(NULL) != pid) 
            ;
        // waitpid(pid, NULL, 0);
        // printf("\nhhhh\n");
    }
    if (pid == 0) {
        setpgid(0, 0);
        signal(SIGINT, SIG_DFL);
        signal(SIGQUIT, SIG_DFL);
        execvp(cmd.args[0], cmd.args);
        exit(EXIT_FAILURE);
    }

    return 0;
}