#ifndef _DEF_H_
#define _DEF_H_

#define ARG_MAX 18
#define CMDLINE_MAX 1024

typedef struct cmd
{
    char* args[ARG_MAX];
} CMD;

#endif /* _DEF_H_ */