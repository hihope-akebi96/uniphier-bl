/*
 * Copyright (C) 2017 Socionext Inc.
 *   Author: Masahiro Yamada <yamada.masahiro@socionext.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <compiler.h>

#define ENTRY(name)						\
	void __noreturn __section(.text_entry_##name) entry_##name(void)

#endif /* __ENTRY_H__ */
