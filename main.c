#include "parse.h"
#include "init.h"
#include "def.h"

char cmdline[CMDLINE_MAX];  /* 存放读取的命令 */
char argline[CMDLINE_MAX];  /* 存放解析出来的参数 */
char *cmdptr;   /* 指向cmdline */
char *argptr;   /* 指向argline */
CMD cmd;

int cmd_count;  /* 命令个数 */

int main()
{
    setup();
    shell_loop();

    return 0;
}