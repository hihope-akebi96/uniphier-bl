// SPDX-License-Identifier: GPL-2.0-or-later
//
// Copyright (C) 2017 Socionext Inc.
//   Author: Masahiro Yamada <yamada.masahiro@socionext.com>

#include <compiler.h>
#include <entry.h>
#include <init.h>
#include <io.h>

#define SC_CPU_GEAR_BASE	(IOMEM(0x61848000))
#define SC_CA53_GEAR_SET	((SC_CPU_GEAR_BASE) + 0x84)
#define SC_CA53_GEAR_UPD	((SC_CPU_GEAR_BASE) + 0x88)

static int ld11_soc_init(const struct board_data *bd)
{
	pll_set_freq(0, 1960, 2);	/* CPLL: 2000MHz -> 1960MHz */
	writel(0, SC_CA53_GEAR_SET);	/* Gear0: CPLL/2 */
	writel(1, SC_CA53_GEAR_UPD);	/* update */

	return 0;
}

static const struct soc_data ld11_data = {
	.soc_id = 0x31,
	.uart_clk_bits = 0x80,
	.uart_clk_rate = 58823529,
	.uart_pinmux = {
		{ .pin = 54, .mux = 0, },
		{ .pin = 58, .mux = 1, },
		{ .pin = 90, .mux = 1, },
		{ .pin = 94, .mux = 1, },
	},
	.stack_base = 0x30014c00,
	.timer_clk_rate = 50000000,
	.dram_rst_bits = 0x00000003,
	.dram_clk_bits = 0x00000003,
	.dram_default_freq = 1600,
	.dram_default_width = { 16, 16, },
	.dram_have_ch2 = 0,
	.dpll = { 6, -1, -1, },
	.umc_init = ld11_umc_init,
	.soc_init = ld11_soc_init,
};

static const struct board_data ld11_ref_data = {
	.board_name = "LD11 Reference",
	.soc_data = &ld11_data,
	.uart_port = 0,
	.dram_ch[0] = {
		.size = 0x20000000,
	},
	.dram_ch[1] = {
		.size = 0x20000000,
	},
};
BOARD_DECLARE(ld11_ref, ld11_ref_data);

static const struct board_data ld11_global_data = {
	.board_name = "LD11 Global",
	.soc_data = &ld11_data,
	.uart_port = 0,
	.dram_ch[0] = {
		.size = 0x20000000,
	},
	.dram_ch[1] = {
		.size = 0x20000000,
	},
};
BOARD_DECLARE(ld11_global, ld11_global_data);