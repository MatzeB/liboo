/*
 * This file is part of cparser.
 * Copyright (C) 2007-2009 Matthias Braun <matze@braunis.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "config.h"

static inline __attribute__((noreturn, format(printf, 1, 2)))
void panic(const char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
#ifdef __OCTOPOS__
	puts("Panic: ");
	vprintf(fmt, ap);
	putchar('\n');
#else
	fputs("Panic: ", stderr);
	vfprintf(stderr, fmt, ap);
	fputc('\n', stderr);
#endif
	va_end(ap);

	abort();
}
