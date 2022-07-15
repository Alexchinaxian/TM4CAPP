/*
 * uart_app.c
 *
 *  Created on: 2022年6月21日
 *      Author: Xiao.Hexin.Alex
 */
#include "main.h"


int UART0_ReceivePacket(Receive_Package *packet){
    uint16_t index;
    packet->ID = UARTCharGet(UART0_BASE);
    packet->CMD = UARTCharGet(UART0_BASE);
    packet->ADDRESS.addressH= UARTCharGet(UART0_BASE);
    packet->ADDRESS.addressL= UARTCharGet(UART0_BASE);
    if(packet->ADDRESS.Address == 0x6001){
        packet->packetData[1] = UARTCharGet(UART0_BASE);
    }
    else if(packet->ADDRESS.Address == 0x6002){
       for (index = 0;index < 3; index++) {
           packet->packetData[index] = UARTCharGet(UART0_BASE);
       }
    }
    else{
    }
    packet->CRC.crc_H= UARTCharGet(UART0_BASE);
    packet->CRC.crc_L= UARTCharGet(UART0_BASE);
    return(0);
}


void UART0_sendPacket(Send_Package *p) {
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, GPIO_PIN_2);
    UART0_WriteByte(UART0_BASE, p->ID);
    UART0_WriteByte(UART0_BASE, p->Function_Code);
    UART0_WriteByte(UART0_BASE, p->ADDRESS.addressH);
    UART0_WriteByte(UART0_BASE, p->ADDRESS.addressL);
    if(p->ADDRESS.Address == 0x6003){
        return;
    }
    UART0_WriteByte(UART0_BASE, p->packetData);
    UART0_WriteByte(UART0_BASE,p->CRC.crc_H );
    UART0_WriteByte(UART0_BASE,p->CRC.crc_L );
    GPIOPinWrite(GPIO_PORTA_BASE, GPIO_PIN_2, 0);
}
