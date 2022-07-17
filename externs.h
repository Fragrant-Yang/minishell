#ifndef _EXTERNS_H_
#define _EXTERNS_H_

#include "def.h"
extern char cmdline[CMDLINE_MAX];
extern char argline[CMDLINE_MAX];
extern char *cmdptr;
extern char *argptr;

extern CMD cmd;

int cmd_count;

#endif /* externs.h */