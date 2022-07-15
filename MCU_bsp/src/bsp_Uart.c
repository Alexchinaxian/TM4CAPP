#include "main.h"
void UART_init(void){
    void UART0_Init();
}
void UART0_Init(void){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTConfigSetExpClk(UART0_BASE, g_ui32SysClock, 115200,
                            (UART_CONFIG_WLEN_8 |  UART_CONFIG_STOP_ONE |
                             UART_CONFIG_PAR_NONE));
    IntEnable(INT_UART0);
    UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    IntMasterEnable();
    IntEnable(INT_UART0);
 }

void UART0_IntHandler(void){
    uint32_t ui32Status;
    ui32Status = UARTIntStatus(UART0_BASE, true);
    UART0_ReceivePacket(&rxBuffer);
    memcpy(&Buffer,&rxBuffer,sizeof(Receive_Package));
    Reciveflag = 1;
    UARTIntClear(UART0_BASE, ui32Status);

}
void UART0_Receive(uint8_t *pui8Data, uint32_t ui32Size){
    while(ui32Size--)
    {
        while((HWREG(UART0_BASE + UART_O_FR) & UART_FR_RXFE))
        {
        }
        *pui8Data++ = HWREG(UART0_BASE + UART_O_DR);
    }
}

void UART0_WriteByte(uint32_t uart_base, char byte) {
    UARTCharPut(uart_base, byte);
    while(UARTBusy(uart_base));
}
