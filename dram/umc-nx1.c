// SPDX-License-Identifier: GPL-2.0-or-later
//
// Copyright (C) 2019 Socionext Inc.

#include <io.h>
#include <types.h>
#include <umc.h>

static void iowrite(u32 addr, u32 data)
{
	writel(data, (void __iomem *)(unsigned long)addr);
}

/**
 * @file umc_init.c
 * @par Note
 *   This file is generated from umc-init script file
 */

static void io_polling_umc(u32 address, u32 expval, u32 mask)
{
	u32 nmask = ~mask ;
	u32 data ;
	do {
		data = readl((void __iomem *)(unsigned long)address) & nmask ;
	} while(data != expval) ;
}

int nx1_umc_init(const struct board_data *bd)
{
	// H15 --------------------
	// UMCINITSET_UMC-CH0
	iowrite(0x1B807700, 0x00000100);

	// H16 --------------------
	// UMCINITSTAT_UMC-CH0
	io_polling_umc(0x1B807900, 0, 0xFFFFFEFF);

	// H17 --------------------
	// UMCDFILPCTLA_UMC-CH0
	iowrite(0x1B807450, 0x80000000);

	// H18 --------------------
	// UMCSPCSETE_UMC-CH0
	iowrite(0x1B807804, 0x10000000);

	// H19 --------------------
	// UMCSPCSETE_UMC-CH0
	iowrite(0x1B807804, 0x00000000);

	// H20 --------------------
	// UMCSPCSETF_UMC-CH0
	iowrite(0x1B807808, 0x00000001);

	// H21 --------------------
	// UMCDFISTCTLC_UMC-CH0
	iowrite(0x1B807458, 0x40000000);

	// H23 --------------------
	// PGCR0_PHY-CH0
	//
	iowrite(0x1E200010, 0x07D81E00);

	// H24 --------------------
	// PGCR1_PHY-CH0
	//
	iowrite(0x1E200014, 0x0200C6A0);

	// H25 --------------------
	// PGCR2_PHY-CH0
	//
	iowrite(0x1E200018, 0x0000B540);

	// H26 --------------------
	// PGCR3_PHY-CH0
	//
	iowrite(0x1E20001C, 0xF0AA0040);

	// H27 --------------------
	// PGCR4_PHY-CH0
	//
	iowrite(0x1E200020, 0x40000000);

	// H28 --------------------
	// PGCR5_PHY-CH0
	//
	iowrite(0x1E200024, 0x01010000);

	// H29 --------------------
	// PGCR6_PHY-CH0
	//
	iowrite(0x1E200028, 0x00010000);

	// H30 --------------------
	// PGCR7_PHY-CH0
	//
	//iowrite(0x1E20002C, 0x00040000);
	iowrite(0x1E20002C, 0x80040000);

	// H31 --------------------
	// PGCR8_PHY-CH0
	//
	iowrite(0x1E200030, 0x00000080);

	// H32 --------------------
	// PTR0_PHY-CH0
	//
	iowrite(0x1E200040, 0x53629AD0);

	// H33 --------------------
	// PTR1_PHY-CH0
	//
	iowrite(0x1E200044, 0x208D9771);

	// H34 --------------------
	// PTR2_PHY-CH0
	//
	iowrite(0x1E200048, 0x00083DEF);

	// H35 --------------------
	// PTR3_PHY-CH0
	//
	iowrite(0x1E20004C, 0x2EBA3161);

	// H36 --------------------
	// PTR4_PHY-CH0
	//
	iowrite(0x1E200050, 0x1003FFFF);

	// H37 --------------------
	// PTR5_PHY-CH0
	//
	iowrite(0x1E200054, 0x2042C216);

	// H38 --------------------
	// PTR6_PHY-CH0
	//
	iowrite(0x1E200058, 0x00000D06);

	// H39 --------------------
	// PLLCR_PHY-CH0
	//
	iowrite(0x1E200080, 0x00038000);

	// H40 --------------------
	// ZQCR_PHY-CH0
	//
	iowrite(0x1E200680, 0x00058F00);

	// H41 --------------------
	// ZQ0PR_PHY-CH0
	//
	iowrite(0x1E200684, 0x10079900);

	// H42 --------------------
	// ZQ1PR_PHY-CH0
	//
	iowrite(0x1E200694, 0x100BDD00);

	// H43 --------------------
	// ZQ2PR_PHY-CH0
	//
	iowrite(0x1E2006A4, 0x100BDD00);

	// H44 --------------------
	// DCR_PHY-CH0
	//
	iowrite(0x1E200100, 0x0000040C);

	// H45 --------------------
	// MR0_PHY-CH0
	//
	iowrite(0x1E200180, 0x00000A44);

	// H46 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H47 --------------------
	// MR1_PHY-CH0
	//
	iowrite(0x1E200184, 0x00000103);

	// H48 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H49 --------------------
	// MR2_PHY-CH0
	//
	iowrite(0x1E200188, 0x00000030);

	// H50 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H51 --------------------
	// MR3_PHY-CH0
	//
	iowrite(0x1E20018C, 0x00000000);

	// H52 --------------------
	// MR4_PHY-CH0
	//
	iowrite(0x1E200190, 0x00000000);

	// H53 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H54 --------------------
	// MR5_PHY-CH0
	//
	iowrite(0x1E200194, 0x00000440);

	// H55 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H56 --------------------
	// MR6_PHY-CH0
	//
	iowrite(0x1E200198, 0x00000C00);

	// H57 --------------------
	// DTPR0_PHY-CH0
	//
	iowrite(0x1E200110, 0x092B140A);

	// H58 --------------------
	// DTPR1_PHY-CH0
	//
	iowrite(0x1E200114, 0x28280010);

	// H59 --------------------
	// DTPR2_PHY-CH0
	//
	iowrite(0x1E200118, 0x10080356);

	// H60 --------------------
	// DTPR3_PHY-CH0
	//
	iowrite(0x1E20011C, 0x03560101);

	// H61 --------------------
	// DTPR4_PHY-CH0
	//
	iowrite(0x1E200120, 0x01D30F08);

	// H62 --------------------
	// DTPR5_PHY-CH0
	//
	iowrite(0x1E200124, 0x003F140A);

	// H63 --------------------
	// DTPR6_PHY-CH0
	//
	iowrite(0x1E200128, 0x00000505);

	// H64 --------------------
	// DXCCR_PHY-CH0
	//
	iowrite(0x1E200088, 0x20C01004);

	// H65 --------------------
	// DSGCR_PHY-CH0
	//
	iowrite(0x1E200090, 0x0064401E);

	// H66 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H67 --------------------
	// ODTCR_PHY-CH0
	//
	iowrite(0x1E200098, 0x00010000);

	// H68 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000001);

	// H69 --------------------
	// ODTCR_PHY-CH0
	//
	iowrite(0x1E200098, 0x00020000);

	// H70 --------------------
	// AACR_PHY-CH0
	//
	iowrite(0x1E2000A0, 0x000000FF);

	// H71 --------------------
	// DTCR0_PHY-CH0
	//
	iowrite(0x1E200200, 0x0000B0C7);

	// H72 --------------------
	// DTCR1_PHY-CH0
	//
	iowrite(0x1E200204, 0x00030A31);

	// H76 --------------------
	// ACIOCR0_PHY-CH0
	//
	iowrite(0x1E200500, 0x30000410);

	// H77 --------------------
	// ACIOCR1_PHY-CH0
	//
	iowrite(0x1E200504, 0x00000000);

	// H78 --------------------
	// ACIOCR2_PHY-CH0
	//
	iowrite(0x1E200508, 0x00000000);

	// H79 --------------------
	// ACIOCR3_PHY-CH0
	//
	iowrite(0x1E20050C, 0x00000000);

	// H80 --------------------
	// ACIOCR4_PHY-CH0
	//
	iowrite(0x1E200510, 0x00000000);

	// H83 --------------------
	// DX0GCR0_PHY-CH0
	//
	iowrite(0x1E200700, 0x40400205);

	// H84 --------------------
	// DX0GCR1_PHY-CH0
	//
	iowrite(0x1E200704, 0x00000000);

	// H85 --------------------
	// DX0GCR2_PHY-CH0
	//
	iowrite(0x1E200708, 0x00000000);

	// H86 --------------------
	// DX0GCR3_PHY-CH0
	//
	iowrite(0x1E20070C, 0xF7FC0000);

	// H87 --------------------
	// DX0GCR4_PHY-CH0
	//
	iowrite(0x1E200710, 0x0E00000C);

	// H88 --------------------
	// DX0GCR5_PHY-CH0
	//
	iowrite(0x1E200714, 0x2F2F2F2F);

	// H89 --------------------
	// DX0GCR6_PHY-CH0
	//
	iowrite(0x1E200718, 0x09090909);

	// H90 --------------------
	// DX1GCR0_PHY-CH0
	//
	iowrite(0x1E200800, 0x40400205);

	// H91 --------------------
	// DX1GCR1_PHY-CH0
	//
	iowrite(0x1E200804, 0x00000000);

	// H92 --------------------
	// DX1GCR2_PHY-CH0
	//
	iowrite(0x1E200808, 0x00000000);

	// H93 --------------------
	// DX1GCR3_PHY-CH0
	//
	iowrite(0x1E20080C, 0xF7FC0000);

	// H94 --------------------
	// DX1GCR4_PHY-CH0
	//
	iowrite(0x1E200810, 0x0E00000C);

	// H95 --------------------
	// DX1GCR5_PHY-CH0
	//
	iowrite(0x1E200814, 0x2F2F2F2F);

	// H96 --------------------
	// DX1GCR6_PHY-CH0
	//
	iowrite(0x1E200818, 0x09090909);

	// H97 --------------------
	// DX2GCR0_PHY-CH0
	//
	iowrite(0x1E200900, 0x40400205);

	// H98 --------------------
	// DX2GCR1_PHY-CH0
	//
	iowrite(0x1E200904, 0x00000000);

	// H99 --------------------
	// DX2GCR2_PHY-CH0
	//
	iowrite(0x1E200908, 0x00000000);

	// H100 --------------------
	// DX2GCR3_PHY-CH0
	//
	iowrite(0x1E20090C, 0xF7FC0000);

	// H101 --------------------
	// DX2GCR4_PHY-CH0
	//
	iowrite(0x1E200910, 0x0E00000C);

	// H102 --------------------
	// DX2GCR5_PHY-CH0
	//
	iowrite(0x1E200914, 0x2F2F2F2F);

	// H103 --------------------
	// DX2GCR6_PHY-CH0
	//
	iowrite(0x1E200918, 0x09090909);

	// H104 --------------------
	// DX3GCR0_PHY-CH0
	//
	iowrite(0x1E200A00, 0x40400205);

	// H105 --------------------
	// DX3GCR1_PHY-CH0
	//
	iowrite(0x1E200A04, 0x00000000);

	// H106 --------------------
	// DX3GCR2_PHY-CH0
	//
	iowrite(0x1E200A08, 0x00000000);

	// H107 --------------------
	// DX3GCR3_PHY-CH0
	//
	iowrite(0x1E200A0C, 0xF7FC0000);

	// H108 --------------------
	// DX3GCR4_PHY-CH0
	//
	iowrite(0x1E200A10, 0x0E00000C);

	// H109 --------------------
	// DX3GCR5_PHY-CH0
	//
	iowrite(0x1E200A14, 0x2F2F2F2F);

	// H110 --------------------
	// DX3GCR6_PHY-CH0
	//
	iowrite(0x1E200A18, 0x09090909);

	// H111 --------------------
	// VTCR0_PHY-CH0
	//
	iowrite(0x1E200528, 0x70032020);

	// H112 --------------------
	// VTCR1_PHY-CH0
	//
	iowrite(0x1E20052C, 0x0FC08096);

	// H116 --------------------
	// PIR_PHY-CH0
	//
	iowrite(0x1E200004, 0x00000073);

	// H117 --------------------
	// PGSR0_PHY-CH0
	//
	io_polling_umc(0x1E200034, 1, 0xFFFFFFFE);

	// H124 --------------------
	// PIR_PHY-CH0
	//
	iowrite(0x1E200004, 0x00000181);

	// H125 --------------------
	// PGSR0_PHY-CH0
	//
	io_polling_umc(0x1E200034, 1, 0xFFFFFFFE);

	// H126 --------------------
	// PGCR1_PHY-CH0
	//
	iowrite(0x1E200014, 0x0200C6E0);

	// H127 --------------------
	// SCHCR1_PHY-CH0
	//
	iowrite(0x1E20016C, 0x000C8064);

	// H128 --------------------
	// SCHCR0_PHY-CH0
	//
	iowrite(0x1E200168, 0x00000011);

	// H130 --------------------
	// PGCR1_PHY-CH0
	//
	iowrite(0x1E200014, 0x0200C6A0);

	// H132 --------------------
	// PGCR1_PHY-CH0
	//
	iowrite(0x1E200014, 0x0200C6E0);

	// H133 --------------------
	// SCHCR1_PHY-CH0
	//
	iowrite(0x1E20016C, 0x000C9F64);

	// H134 --------------------
	// SCHCR0_PHY-CH0
	// wait(100ns)
	iowrite(0x1E200168, 0x00000011);

	// H136 --------------------
	// PGCR1_PHY-CH0
	//
	iowrite(0x1E200014, 0x0200C6A0);

	// H137 --------------------
	// PGCR1_PHY-CH0
	//
	iowrite(0x1E200014, 0x0200C6E0);

	// H138 --------------------
	// SCHCR1_PHY-CH0
	//
	iowrite(0x1E20016C, 0x000C0064);

	// H139 --------------------
	// SCHCR0_PHY-CH0
	//
	iowrite(0x1E200168, 0x00000011);

	// H141 --------------------
	// PGCR1_PHY-CH0
	//
	iowrite(0x1E200014, 0x0200C6A0);

	// H144 --------------------
	// UMCCMDCTLA_UMC-CH0
	iowrite(0x1B807180, 0x0814142B);

	// H145 --------------------
	// UMCCMDCTLB_UMC-CH0
	iowrite(0x1B807184, 0x3F282A0A);

	// H146 --------------------
	// UMCCMDCTLC_UMC-CH0
	iowrite(0x1B807188, 0x201A0C04);

	// H147 --------------------
	// UMCCMDCTLDDR4A_UMC-CH0
	iowrite(0x1B80718C, 0x00000009);

	// H148 --------------------
	// UMCCMDCTLDDR4B_UMC-CH0
	iowrite(0x1B807190, 0x00200007);

	// H149 --------------------
	// UMCCMDCTLE_UMC-CH0
	iowrite(0x1B807200, 0x017109F0);

	// H150 --------------------
	// UMCCMDCTLF_UMC-CH0
	iowrite(0x1B807204, 0x00030176);

	// H151 --------------------
	// UMCCMDCTLG_UMC-CH0
	iowrite(0x1B807208, 0x04040207);

	// H152 --------------------
	// UMCCMDCTLH_UMC-CH0
	iowrite(0x1B80720C, 0x03F8FF90);

	// H153 --------------------
	// UMCRDATACTL_D0_UMC-CH0
	iowrite(0x1B807400, 0x00000010);

	// H154 --------------------
	// UMCRDATACTL_D1_UMC-CH0
	iowrite(0x1B807404, 0x00000010);

	// H155 --------------------
	// UMCWDATACTL_D0_UMC-CH0
	iowrite(0x1B807408, 0x00000C10);

	// H156 --------------------
	// UMCWDATACTL_D1_UMC-CH0
	iowrite(0x1B807410, 0x00000C10);

	// H157 --------------------
	// UMCDATASET_D0_UMC-CH0
	iowrite(0x1B807418, 0x00000000);

	// H158 --------------------
	// UMCDATASET_D1_UMC-CH0
	iowrite(0x1B80741C, 0x00000000);

	// H159 --------------------
	// UMCDBICTL_D0_UMC-CH0
	iowrite(0x1B807420, 0x00000100);

	// H160 --------------------
	// UMCDBICTL_D1_UMC-CH0
	iowrite(0x1B807424, 0x00000100);

	// H161 --------------------
	// UMCACCESSCTL_D0_UMC-CH0
	iowrite(0x1B807428, 0x00001111);

	// H162 --------------------
	// UMCACCESSCTL_D1_UMC-CH0
	iowrite(0x1B80742C, 0x00001111);

	// H163 --------------------
	// UMCODTCTL_D0_UMC-CH0
	iowrite(0x1B8070E0, 0x42000203);

	// H164 --------------------
	// UMCODTCTL_D1_UMC-CH0
	iowrite(0x1B8070E4, 0x42000203);

	// H165 --------------------
	// UMCMEMCONF0A_UMC-CH0
	// DRAMÍÆÎÌ(32Gb)ÀßÄê
	iowrite(0x1B807000, 0x00000C01);

	// H166 --------------------
	// UMCMEMCONF0B_UMC-CH0
	iowrite(0x1B807004, 0x00001450);

	// H167 --------------------
	// UMCMEMCONFCH_UMC-CH0
	iowrite(0x1B807010, 0x00033C04);

	// H168 --------------------
	// UMCMEMMAPSETA_UMC-CH0
	iowrite(0x1B807014, 0x00000001);

	// H169 --------------------
	// UMCCELLCTRL_UMC-CH0
	iowrite(0x1B807684, 0x00006048);

	// H170 --------------------
	// UMCACSSETA_UMC-CH0
	iowrite(0x1B807380, 0x00010001);

	// H171 --------------------
	// UMCFLOWCTLG_UMC-CH0
	iowrite(0x1B807694, 0x00000103);

	// H172 --------------------
	// UMCSPCSETB_UMC-CH0
	iowrite(0x1B807300, 0x00020200);

	// H174 --------------------
	// EGW0_RST_NoC
	iowrite(0x1B680004, 0x0000FFFF);

	// H175 --------------------
	// EGW1_RST_NoC
	iowrite(0x1B681004, 0x0000FFFF);

	// H176 --------------------
	// EGW2_RST_NoC
	iowrite(0x1B682004, 0x0000FFFF);

	// H177 --------------------
	// EGW3_RST_NoC
	iowrite(0x1B683004, 0x0000FFFF);

	// H179 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H180 --------------------
	// DX0LCDLR2_PHY-CH0
	//
	iowrite(0x1E200788, 0x00000016);

	// H181 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000001);

	// H182 --------------------
	// DX0LCDLR2_PHY-CH0
	//
	iowrite(0x1E200788, 0x00000016);

	// H183 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H184 --------------------
	// DX0GTR0_PHY-CH0
	//
	iowrite(0x1E2007C0, 0x00020002);

	// H185 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000001);

	// H186 --------------------
	// DX0GTR0_PHY-CH0
	//
	iowrite(0x1E2007C0, 0x00020002);

	// H187 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H188 --------------------
	// DX1LCDLR2_PHY-CH0
	//
	iowrite(0x1E200888, 0x00000016);

	// H189 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000001);

	// H190 --------------------
	// DX1LCDLR2_PHY-CH0
	//
	iowrite(0x1E200888, 0x00000016);

	// H191 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H192 --------------------
	// DX1GTR0_PHY-CH0
	//
	iowrite(0x1E2008C0, 0x00020002);

	// H193 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000001);

	// H194 --------------------
	// DX1GTR0_PHY-CH0
	//
	iowrite(0x1E2008C0, 0x00020002);

	// H195 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H196 --------------------
	// DX2LCDLR2_PHY-CH0
	//
	iowrite(0x1E200988, 0x00000016);

	// H197 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000001);

	// H198 --------------------
	// DX2LCDLR2_PHY-CH0
	//
	iowrite(0x1E200988, 0x00000016);

	// H199 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H200 --------------------
	// DX2GTR0_PHY-CH0
	//
	iowrite(0x1E2009C0, 0x00020002);

	// H201 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000001);

	// H202 --------------------
	// DX2GTR0_PHY-CH0
	//
	iowrite(0x1E2009C0, 0x00020002);

	// H203 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H204 --------------------
	// DX3LCDLR2_PHY-CH0
	//
	iowrite(0x1E200A88, 0x00000016);

	// H205 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000001);

	// H206 --------------------
	// DX3LCDLR2_PHY-CH0
	//
	iowrite(0x1E200A88, 0x00000016);

	// H207 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000000);

	// H208 --------------------
	// DX3GTR0_PHY-CH0
	//
	iowrite(0x1E200AC0, 0x00020002);

	// H209 --------------------
	// RANKIDR_PHY-CH0
	//
	iowrite(0x1E2004DC, 0x00000001);

	// H210 --------------------
	// DX3GTR0_PHY-CH0
	//
	iowrite(0x1E200AC0, 0x00020002);

	return 0;
}
