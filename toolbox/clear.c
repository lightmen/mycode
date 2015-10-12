#include <stdio.h>

int clear_main(int argc, char **argv)
{
	/* This prints the clear screen and move cursor to top-left corner control
     * characters for VT100 terminals. This means it will not work on
     * non-VT100 compliant terminals, namely Windows' cmd.exe, but should
     * work on anything unix-y. */
	fputs("\x1b[2J\x1b[H",stdout);
	return 0;
}
