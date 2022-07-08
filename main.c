#include "parse.h"
#include "init.h"

char cmdline[100];

int main()
{
    setup();
    shell_loop();

    return 0;
}