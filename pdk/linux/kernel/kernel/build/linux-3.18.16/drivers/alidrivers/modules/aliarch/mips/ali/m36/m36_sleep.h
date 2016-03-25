/**
* Copyright (c) 2011,Ali Corp.
* All rights reserved.
*
* FileName     : m36_sleep.h
* Verison      : 1.0
* Author       : Zhao Owen
* Date         : 2012-5-14
* Description  : The MACROs in this header is dedicated to fast standby.
*                Do not use for any other process
*/
#ifndef __ASM_ALI_M36_SLEEP_XXXXXXXXXXX______
#define __ASM_ALI_M36_SLEEP_XXXXXXXXXXX______

/* IR HW registers define */
#define SYS_IC_SB_BASE_H        0xb8018100
#define SYS_IC_SB_IRC_CFG       0x0
#define SYS_IC_SB_IRC_FCTRL     0x1
#define SYS_IC_SB_IRC_TTHR      0x2
#define SYS_IC_SB_IRC_NTHR      0x3
#define SYS_IC_SB_IRC_IER       0x6
#define SYS_IC_SB_IRC_ISR       0x7
#define SYS_IC_SB_IRC_DATA      0x8
#define SYS_IC_SB_IRC_BITIE     0x80000

/* IR pulse width buffer ---- in cache */
//#define IR_RLC_BUFFER_START     0x88000000
#define IR_RLC_BUFFER_START     0x87000000
#define IR_RLC_BUFFER_SIZE      256
#define IR_RLC_BUFFER_WTMRK     192

/* IR decoder related macro */
#define IR_TYPE_NUM             5
#define IR_PATTERN_START        (IR_RLC_BUFFER_START + IR_RLC_BUFFER_SIZE)
#define IR_PATTERN_SIZE         240
#define IR_PATTERN_CNT_START    (IR_PATTERN_START + IR_PATTERN_SIZE)
#define IR_PATTERN_CNT_SIZE     16
#define IR_ATTR_START           (IR_PATTERN_CNT_START + IR_PATTERN_CNT_SIZE)
#define IR_ATTR_SIZE            64
#define IR_DECODER_START        (IR_ATTR_START + (IR_ATTR_SIZE * IR_TYPE_NUM))
#define IR_DECODER_SIZE         40
#define IR_PLS_SUM              (IR_DECODER_START + (IR_DECODER_SIZE * IR_TYPE_NUM))
#define IR_RC6_FLG              (IR_PLS_SUM + 4)
#define IR_CACHE_END            (IR_RC6_FLG + 4)

#define IR_CTL_REG_SAVE            (IR_CACHE_END + 4)

#define DDR_PHY1_PHY2_ENABLE		(IR_CTL_REG_SAVE+4)
#define MEM_CLK_SAVE		(IR_CTL_REG_SAVE+4*2)
#define DDR_PHY1_START		MEM_CLK_SAVE
#define DDR_PHY1_PGCR0		(DDR_PHY1_START + 4)
#define DDR_PHY1_PGCR1		(DDR_PHY1_START + 4 * 2)
#define DDR_PHY1_PLLCR		(DDR_PHY1_START + 4 * 3)
#define DDR_PHY1_PTR0		(DDR_PHY1_START + 4 * 4)
#define DDR_PHY1_PTR1		(DDR_PHY1_START + 4 * 5)
#define DDR_PHY1_PTR2		(DDR_PHY1_START + 4 * 6)
#define DDR_PHY1_PTR3		(DDR_PHY1_START + 4 * 7)
#define DDR_PHY1_PTR4		(DDR_PHY1_START + 4 * 8)
#define DDR_PHY1_ACMDLR	(DDR_PHY1_START + 4 * 9)
#define DDR_PHY1_ACDBLR	(DDR_PHY1_START + 4 * 10)
#define DDR_PHY1_ACIOCR	(DDR_PHY1_START + 4 * 11)
#define DDR_PHY1_DXCCR		(DDR_PHY1_START + 4 * 12)
#define DDR_PHY1_DSGCR		(DDR_PHY1_START + 4 * 13)
#define DDR_PHY1_DCR		(DDR_PHY1_START + 4 * 14)
#define DDR_PHY1_DTPR0		(DDR_PHY1_START + 4 * 15)
#define DDR_PHY1_DTPR1		(DDR_PHY1_START + 4 * 16)
#define DDR_PHY1_DTPR2		(DDR_PHY1_START + 4 * 17)
#define DDR_PHY1_MR0_MR	(DDR_PHY1_START + 4 * 18)
#define DDR_PHY1_MR1_EMR	(DDR_PHY1_START + 4 * 19)
#define DDR_PHY1_MR2		(DDR_PHY1_START + 4 * 20)
#define DDR_PHY1_MR3		(DDR_PHY1_START + 4 * 21)
#define DDR_PHY1_PGCR2		(DDR_PHY1_START + 4 * 22)
#define DDR_PHY1_ZQ0CR0	(DDR_PHY1_START + 4 * 23)
#define DDR_PHY1_ZQ0CR1	(DDR_PHY1_START + 4 * 24)
#define DDR_PHY1_ZQ0SR0	(DDR_PHY1_START + 4 * 25)
#define DDR_PHY1_ZQ0SR1	(DDR_PHY1_START + 4 * 26)
#define DDR_PHY1_DX0GCR	(DDR_PHY1_START + 4 * 27)
#define DDR_PHY1_DX0BDLR0		(DDR_PHY1_START + 4 * 28)
#define DDR_PHY1_DX0BDLR1		(DDR_PHY1_START + 4 * 29)
#define DDR_PHY1_DX0BDLR2		(DDR_PHY1_START + 4 * 30)
#define DDR_PHY1_DX0BDLR3		(DDR_PHY1_START + 4 * 31)
#define DDR_PHY1_DX0BDLR4		(DDR_PHY1_START + 4 * 32)
#define DDR_PHY1_DX0LCDLR0		(DDR_PHY1_START + 4 * 33)
#define DDR_PHY1_DX0LCDLR1		(DDR_PHY1_START + 4 * 34)
#define DDR_PHY1_DX0LCDLR2		(DDR_PHY1_START + 4 * 35)
#define DDR_PHY1_DX0MDLR		(DDR_PHY1_START + 4 * 36)
#define DDR_PHY1_DX0GTR		(DDR_PHY1_START + 4 * 37)
#define DDR_PHY1_DX1GCR		(DDR_PHY1_START + 4 * 38)
#define DDR_PHY1_DX1BDLR0		(DDR_PHY1_START + 4 * 39)
#define DDR_PHY1_DX1BDLR1		(DDR_PHY1_START + 4 * 40)
#define DDR_PHY1_DX1BDLR2		(DDR_PHY1_START + 4 * 41)
#define DDR_PHY1_DX1BDLR3		(DDR_PHY1_START + 4 * 42)
#define DDR_PHY1_DX1BDLR4		(DDR_PHY1_START + 4 * 43)
#define DDR_PHY1_DX1LCDLR0		(DDR_PHY1_START + 4 * 44)
#define DDR_PHY1_DX1LCDLR1		(DDR_PHY1_START + 4 * 45)
#define DDR_PHY1_DX1LCDLR2		(DDR_PHY1_START + 4 * 46)
#define DDR_PHY1_DX1MDLR		(DDR_PHY1_START + 4 * 47)
#define DDR_PHY1_DX1GTR		(DDR_PHY1_START + 4 * 48)
#define DDR_PHY1_DTCR		(DDR_PHY1_START + 4 * 49)
#define DDR_PHY1_END			DDR_PHY1_DTCR

#define DDR_PHY2_START		DDR_PHY1_END
#define DDR_PHY2_PGCR0		(DDR_PHY2_START + 4)
#define DDR_PHY2_PGCR1		(DDR_PHY2_START + 4 * 2)
#define DDR_PHY2_PLLCR		(DDR_PHY2_START + 4 * 3)
#define DDR_PHY2_PTR0		(DDR_PHY2_START + 4 * 4)
#define DDR_PHY2_PTR1		(DDR_PHY2_START + 4 * 5)
#define DDR_PHY2_PTR2		(DDR_PHY2_START + 4 * 6)
#define DDR_PHY2_PTR3		(DDR_PHY2_START + 4 * 7)
#define DDR_PHY2_PTR4		(DDR_PHY2_START + 4 * 8)
#define DDR_PHY2_ACMDLR	(DDR_PHY2_START + 4 * 9)
#define DDR_PHY2_ACDBLR	(DDR_PHY2_START + 4 * 10)
#define DDR_PHY2_ACIOCR	(DDR_PHY2_START + 4 * 11)
#define DDR_PHY2_DXCCR		(DDR_PHY2_START + 4 * 12)
#define DDR_PHY2_DSGCR		(DDR_PHY2_START + 4 * 13)
#define DDR_PHY2_DCR		(DDR_PHY2_START + 4 * 14)
#define DDR_PHY2_DTPR0		(DDR_PHY2_START + 4 * 15)
#define DDR_PHY2_DTPR1		(DDR_PHY2_START + 4 * 16)
#define DDR_PHY2_DTPR2		(DDR_PHY2_START + 4 * 17)
#define DDR_PHY2_MR0_MR	(DDR_PHY2_START + 4 * 18)
#define DDR_PHY2_MR1_EMR	(DDR_PHY2_START + 4 * 19)
#define DDR_PHY2_MR2		(DDR_PHY2_START + 4 * 20)
#define DDR_PHY2_MR3		(DDR_PHY2_START + 4 * 21)
#define DDR_PHY2_PGCR2		(DDR_PHY2_START + 4 * 22)
#define DDR_PHY2_ZQ0CR0	(DDR_PHY2_START + 4 * 23)
#define DDR_PHY2_ZQ0CR1	(DDR_PHY2_START + 4 * 24)
#define DDR_PHY2_ZQ0SR0	(DDR_PHY2_START + 4 * 25)
#define DDR_PHY2_ZQ0SR1	(DDR_PHY2_START + 4 * 26)
#define DDR_PHY2_DX0GCR	(DDR_PHY2_START + 4 * 27)
#define DDR_PHY2_DX0BDLR0		(DDR_PHY2_START + 4 * 28)
#define DDR_PHY2_DX0BDLR1		(DDR_PHY2_START + 4 * 29)
#define DDR_PHY2_DX0BDLR2		(DDR_PHY2_START + 4 * 30)
#define DDR_PHY2_DX0BDLR3		(DDR_PHY2_START + 4 * 31)
#define DDR_PHY2_DX0BDLR4		(DDR_PHY2_START + 4 * 32)
#define DDR_PHY2_DX0LCDLR0		(DDR_PHY2_START + 4 * 33)
#define DDR_PHY2_DX0LCDLR1		(DDR_PHY2_START + 4 * 34)
#define DDR_PHY2_DX0LCDLR2		(DDR_PHY2_START + 4 * 35)
#define DDR_PHY2_DX0MDLR		(DDR_PHY2_START + 4 * 36)
#define DDR_PHY2_DX0GTR		(DDR_PHY2_START + 4 * 37)
#define DDR_PHY2_DX1GCR		(DDR_PHY2_START + 4 * 38)
#define DDR_PHY2_DX1BDLR0		(DDR_PHY2_START + 4 * 39)
#define DDR_PHY2_DX1BDLR1		(DDR_PHY2_START + 4 * 40)
#define DDR_PHY2_DX1BDLR2		(DDR_PHY2_START + 4 * 41)
#define DDR_PHY2_DX1BDLR3		(DDR_PHY2_START + 4 * 42)
#define DDR_PHY2_DX1BDLR4		(DDR_PHY2_START + 4 * 43)
#define DDR_PHY2_DX1LCDLR0		(DDR_PHY2_START + 4 * 44)
#define DDR_PHY2_DX1LCDLR1		(DDR_PHY2_START + 4 * 45)
#define DDR_PHY2_DX1LCDLR2		(DDR_PHY2_START + 4 * 46)
#define DDR_PHY2_DX1MDLR		(DDR_PHY2_START + 4 * 47)
#define DDR_PHY2_DX1GTR		(DDR_PHY2_START + 4 * 48)
#define DDR_PHY2_DTCR		(DDR_PHY2_START + 4 * 49)
#define DDR_PHY2_END               DDR_PHY2_DTCR

#define DDR_DM_REG1	(DDR_PHY2_END + 4 )
#define DDR_DM_REG2	(DDR_PHY2_END + 4 * 2)
	
#define DDR_ALL_END               DDR_DM_REG2

#define PLL_PM_VALUE_a0          (DDR_ALL_END + 4 * 1)
#define PLL_PM_VALUE_b0          (DDR_ALL_END + 4 * 2)
#define PLL_PM_VALUE_b4          (DDR_ALL_END + 4 * 3)
#define PLL_PM_VALUE_c0          (DDR_ALL_END + 4 * 4)

/* Store the timeout value */
#define PM_SLEEP_TIMEOUT        (PLL_PM_VALUE_c0 + 4 * 1)
#define PM_SLEEP_TIMEOUT_CONST  (PLL_PM_VALUE_c0 + 4 * 2)

/* Store the ir wakeup key */
#define PM_IR_WAKEUP_KEY1  (PM_SLEEP_TIMEOUT_CONST + 4 *1)
#define PM_IR_WAKEUP_KEY2  (PM_SLEEP_TIMEOUT_CONST + 4 *2)
#define PM_IR_WAKEUP_KEY3  (PM_SLEEP_TIMEOUT_CONST + 4 *3)
#define PM_IR_WAKEUP_KEY4  (PM_SLEEP_TIMEOUT_CONST + 4 *4)
#define PM_IR_WAKEUP_KEY5  (PM_SLEEP_TIMEOUT_CONST + 4 *5)
#define PM_IR_WAKEUP_KEY6  (PM_SLEEP_TIMEOUT_CONST + 4 *6)
#define PM_IR_WAKEUP_KEY7  (PM_SLEEP_TIMEOUT_CONST + 4 *7)
#define PM_IR_WAKEUP_KEY8  (PM_SLEEP_TIMEOUT_CONST + 4 *8)

#define SCB_REG0          (PM_IR_WAKEUP_KEY8 + 4 * 1)
#define SCB_REG4          (PM_IR_WAKEUP_KEY8 + 4 * 2)
#define SCB_REG8          (PM_IR_WAKEUP_KEY8 + 4 * 3)

#define STANDBY_TIMER          (SCB_REG8 + 4 * 1)
#define MONTH_ARRAY		(SCB_REG8 + 4 * 2)

#define CONFIGDATA_BASE  (MONTH_ARRAY + 4*4)

/* REG back up buffer ---- in memory */
#define REG_BAK_BUFFER_START    0x88004000
#define REG_BAK_0               (REG_BAK_BUFFER_START + 4 * 0)

#define US_STANDBY_TICKS    (27000000 / 2000000)
#define US_PER_SEC          (1000000)
#define SUSPEND_TICKS2SEC   (1 / (US_STANDBY_TICKS * US_PER_SEC))

//#define TIME_COMPARE_1S     (27000000 / 4)
#define TIME_COMPARE_1S     (27000000 /(4*8))	//SRC_LP_SEL 11: 1/64 CRYSTAL Clock

#endif
