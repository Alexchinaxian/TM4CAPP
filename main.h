#ifndef MAIN_H_
#define MAIN_H_
#include "stdint.h"
#include "stdbool.h"
//硬件层
#include <MCU_bsp/inc/bsp_Timer.h>
#include <MCU_bsp/inc/bsp_Uart.h>
#include <MCU_bsp/inc/bsp_SPI.h>

//接口层
#include <MCU_API/inc/API_Uart.h>
#include <MCU_API/inc/API_SPI.h>

//应用层
#include <MCU_App/inc/app_bootloader.h>


#include "inc/hw_flash.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "inc/hw_uart.h"
#include "inc/hw_nvic.h"

#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/rom_map.h"
#include "driverlib/flash.h"
#include "driverlib/uart.h"
#include "driverlib/rom_map.h"
#include "driverlib/interrupt.h"
#include "driverlib/ssi.h"

#endif /* MAIN_H_ */
