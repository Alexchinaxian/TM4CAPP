/*
 * timer.c
 *
 *  Created on: 2022年7月15日
 *      Author: Xiao.Hexin.Alex
 */
#include "main.h"

void Time_Init(void){
    g_ui32SysClock = SysCtlClockFreqSet((SYSCTL_XTAL_16MHZ |SYSCTL_OSC_MAIN
                        |SYSCTL_USE_PLL |SYSCTL_CFG_VCO_480),80000000);

}



