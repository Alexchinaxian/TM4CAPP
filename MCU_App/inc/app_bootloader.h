/*
 * app_bootloader.h
 *
 *  Created on: 2022年7月15日
 *      Author: Xiao.Hexin.Alex
 */

#ifndef MCU_APP_INC_APP_BOOTLOADER_H_
#define MCU_APP_INC_APP_BOOTLOADER_H_



static bool UpdateFlasg = 0;


void UART_IAP(void);
void UART_BOOT_ExecutiveCommand(Receive_Package *pRxMessage);
void JumpToBootLoader(void);


#endif /* MCU_APP_INC_APP_BOOTLOADER_H_ */
