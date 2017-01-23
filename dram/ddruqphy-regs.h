/*
 * Copyright (C) 2016 Socionext Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __DDRUQPHY_REGS_H__
#define __DDRUQPHY_REGS_H__

#include <utils.h>

#define PHY_REG_SHIFT			2
#define PHY_SLV_DLY_WIDTH		6
#define PHY_BITLVL_DLY_WIDTH		6
#define PHY_MAS_DLY_WIDTH		8

#define PHY_SCL_START			(0x40 << (PHY_REG_SHIFT))
#define   PHY_SCL_START_GO_DONE		BIT(28)
#define PHY_SCL_DATA_0			(0x41 << (PHY_REG_SHIFT))
#define PHY_SCL_DATA_1			(0x42 << (PHY_REG_SHIFT))
#define PHY_SCL_LATENCY			(0x43 << (PHY_REG_SHIFT))
#define PHY_SCL_CONFIG_1		(0x46 << (PHY_REG_SHIFT))
#define PHY_SCL_CONFIG_2		(0x47 << (PHY_REG_SHIFT))
#define PHY_PAD_CTRL			(0x48 << (PHY_REG_SHIFT))
#define PHY_DLL_RECALIB			(0x49 << (PHY_REG_SHIFT))
#define   PHY_DLL_RECALIB_TRIM_MASK	GENMASK(PHY_SLV_DLY_WIDTH - 1, 0)
#define   PHY_DLL_RECALIB_INCR		BIT(27)
#define PHY_DLL_ADRCTRL			(0x4A << (PHY_REG_SHIFT))
#define   PHY_DLL_ADRCTRL_TRIM_MASK	GENMASK(PHY_SLV_DLY_WIDTH - 1, 0)
#define   PHY_DLL_ADRCTRL_INCR		BIT(9)
#define   PHY_DLL_ADRCTRL_MDL_SHIFT	24
#define   PHY_DLL_ADRCTRL_MDL_MASK	(GENMASK(PHY_MAS_DLY_WIDTH - 1, 0) << \
						PHY_DLL_ADRCTRL_MDL_SHIFT)
#define PHY_LANE_SEL			(0x4B << (PHY_REG_SHIFT))
#define   PHY_LANE_SEL_LANE_SHIFT	0
#define   PHY_LANE_SEL_LANE_WIDTH	8
#define   PHY_LANE_SEL_BIT_SHIFT	8
#define   PHY_LANE_SEL_BIT_WIDTH	4
#define PHY_DLL_TRIM_1			(0x4C << (PHY_REG_SHIFT))
#define PHY_DLL_TRIM_2			(0x4D << (PHY_REG_SHIFT))
#define PHY_DLL_TRIM_3			(0x4E << (PHY_REG_SHIFT))
#define PHY_SCL_MAIN_CLK_DELTA		(0x50 << (PHY_REG_SHIFT))
#define PHY_WRLVL_AUTOINC_TRIM		(0x53 << (PHY_REG_SHIFT))
#define PHY_WRLVL_DYN_ODT		(0x54 << (PHY_REG_SHIFT))
#define PHY_WRLVL_ON_OFF		(0x55 << (PHY_REG_SHIFT))
#define PHY_UNQ_ANALOG_DLL_1		(0x57 << (PHY_REG_SHIFT))
#define PHY_UNQ_ANALOG_DLL_2		(0x58 << (PHY_REG_SHIFT))
#define PHY_DLL_INCR_TRIM_1		(0x59 << (PHY_REG_SHIFT))
#define PHY_DLL_INCR_TRIM_3		(0x5A << (PHY_REG_SHIFT))
#define PHY_SCL_CONFIG_3		(0x5B << (PHY_REG_SHIFT))
#define PHY_UNIQUIFY_TSMC_IO_1		(0x5C << (PHY_REG_SHIFT))
#define PHY_SCL_START_ADDR		(0x62 << (PHY_REG_SHIFT))
#define PHY_IP_DQ_DQS_BITWISE_TRIM	(0x65 << (PHY_REG_SHIFT))
#define   PHY_IP_DQ_DQS_BITWISE_TRIM_MASK	\
					GENMASK(PHY_BITLVL_DLY_WIDTH - 1, 0)
#define   PHY_IP_DQ_DQS_BITWISE_TRIM_INC	\
					BIT(PHY_BITLVL_DLY_WIDTH)
#define   PHY_IP_DQ_DQS_BITWISE_TRIM_OVERRIDE	\
					BIT(PHY_BITLVL_DLY_WIDTH + 1)
#define PHY_DSCL_CNT			(0x67 << (PHY_REG_SHIFT))
#define PHY_OP_DQ_DM_DQS_BITWISE_TRIM	(0x68 << (PHY_REG_SHIFT))
#define   PHY_OP_DQ_DM_DQS_BITWISE_TRIM_MASK	\
					GENMASK(PHY_BITLVL_DLY_WIDTH - 1, 0)
#define   PHY_OP_DQ_DM_DQS_BITWISE_TRIM_INC	\
					BIT(PHY_BITLVL_DLY_WIDTH)
#define   PHY_OP_DQ_DM_DQS_BITWISE_TRIM_OVERRIDE	\
					BIT(PHY_BITLVL_DLY_WIDTH + 1)
#define PHY_DLL_TRIM_CLK		(0x69 << (PHY_REG_SHIFT))
#define   PHY_DLL_TRIM_CLK_MASK		GENMASK(PHY_SLV_DLY_WIDTH, 0)
#define   PHY_DLL_TRIM_CLK_INCR		BIT(PHY_SLV_DLY_WIDTH + 1)
#define PHY_DYNAMIC_BIT_LVL		(0x6B << (PHY_REG_SHIFT))
#define PHY_SCL_WINDOW_TRIM		(0x6D << (PHY_REG_SHIFT))
#define PHY_DISABLE_GATING_FOR_SCL	(0x6E << (PHY_REG_SHIFT))
#define PHY_SCL_CONFIG_4		(0x6F << (PHY_REG_SHIFT))
#define PHY_DYNAMIC_WRITE_BIT_LVL	(0x70 << (PHY_REG_SHIFT))
#define PHY_VREF_TRAINING		(0x72 << (PHY_REG_SHIFT))
#define PHY_SCL_GATE_TIMING		(0x78 << (PHY_REG_SHIFT))

#endif /* __DDRUQPHY_REGS_H__ */
