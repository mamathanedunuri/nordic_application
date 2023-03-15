/*
 * Copyright (c) 2017 Linaro Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/*#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/console/console.h>

void main(void)
{
	console_init();

	printk("Start typing characters to see their hex codes printed\n");

	while (1) {
		uint8_t c = console_getchar();
		//printk("char: [0x%x] %c\n", c, c);
	}


	console_getline_init();

	printk("Enter a line\n");

	while (1) {
		char *s = console_getline();

		printk("line: %s\n", s);
		printk("last char was: 0x%x\n", s[strlen(s) - 1]);
	}
}*/
#include <zephyr/kernel.h>
#include <zephyr/console/console.h>

static const char prompt[] = "Start typing characters to see them echoed back\r\n";

void main(void)
{
	console_init();

	printk("You should see another line with instructions below. If not,\n");
	printk("the (interrupt-driven) console device doesn't work as expected:\n");
	console_write(NULL, prompt, sizeof(prompt) - 1);

	while (1) {
		uint8_t c = console_getchar();

		console_putchar(c);
		if (c == '\r') {
			console_putchar('\n');
		}
	}
}

