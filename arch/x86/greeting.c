#include <machine/arch.h>
#include "serial.h"
#include "vga.h"
#include "greeting.h"

void
greeting_screen(void)
{
	static const char *LOGO_ASCII[] = {
		"    ______     _               ___ \n",
		"    |  ___|   | |             |___|\n",
		"    | |_ _   _| | ___   _ _ __ ___  \n",
		"    |  _| | | | |/ / | | | '__/ _ \\ \n",
		"    | | | |_| |   <| |_| | | | (_) |\n",
		"    \\_|  \\__,_|_|\\_\\\\__,_|_|  \\___/ \n",
		(void *)0
	};
	static const char *MESSAGE_AND_COPYRIGHT =
		"                                    v" VERSION " - " COMMIT "\n\n"
		"/!\\ Use serial to interact with me /!\\\n\n"
		"Copyright (C) 2020 d0p1.\n"
		"License GPLv3+: GNU GPL version 3 or later "
		"<https://gnu.org/licenses/gpl.html>.\n"
		"This is free software: you are free to change and redistribute it. \n"
		"There is NO WARRANTY, to the extent permitted by law.\n";

	uint8_t         logo_color;
	int             idx;

	vga_clear();
	logo_color = 0x09;
	for (idx = 0; LOGO_ASCII[idx] != (void *)0; idx++)
	{
		vga_puts(LOGO_ASCII[idx], logo_color++, 0x0);
		debug_puts(LOGO_ASCII[idx]);
	}

	vga_puts(MESSAGE_AND_COPYRIGHT, 0xf, 0x0);
	debug_puts(MESSAGE_AND_COPYRIGHT);
}
