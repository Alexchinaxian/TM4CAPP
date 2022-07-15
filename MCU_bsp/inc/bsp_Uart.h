#ifndef MCU_BSP_INC_UART_DRV_H_
#define MCU_BSP_INC_UART_DRV_H_

#include "stdint.h"
typedef struct {
    union CRC
    {
        uint16_t CRC;
        struct
        {
         uint8_t crc_L;
         uint8_t crc_H;
        };
    }CRC;
    union Address
    {
        uint16_t Address;
        struct
        {
         uint8_t addressL;
         uint8_t addressH;
        };
    }ADDRESS;
    uint8_t packetData[10];
    uint8_t CMD;
    uint8_t ID;
} Receive_Package ;


typedef struct {
    union Send_CRC
    {
        uint16_t CRC;
        struct
        {
         uint8_t crc_L;
         uint8_t crc_H;
        };
    }CRC;
    union Send_Address
    {
        uint16_t Address;
        struct
        {
         uint8_t addressL;
         uint8_t addressH;
        };
    }ADDRESS;
    uint8_t packetData;
    uint8_t Function_Code;
    uint8_t ID;
} Send_Package ;

void UART_init(void);
void UART0_Init(void);
void UART0_IntHandler(void);
void UART0_Receive(uint8_t *pui8Data, uint32_t ui32Size);
void UART0_WriteByte(uint32_t uart_base, char byte);
#endif /* MCU_BSP_INC_UART_DRV_H_ */
