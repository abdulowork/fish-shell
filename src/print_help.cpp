// Print help message for the specified command.
#include "config.h"  // IWYU pragma: keep

#include "print_help.h"

#include <stdio.h>
#include <stdlib.h>

#include <cstring>

#include "common.h"

#define CMD_LEN 1024

#define HELP_ERR "Could not show help message\n"

void print_help(const char *c) {
    char cmd[CMD_LEN];
    int printed = snprintf(cmd, CMD_LEN, "fish -c '__fish_print_help %s'", c);

    if (printed < CMD_LEN && system(cmd) == -1) {
        write_loop(2, HELP_ERR, std::strlen(HELP_ERR));
    }
}
