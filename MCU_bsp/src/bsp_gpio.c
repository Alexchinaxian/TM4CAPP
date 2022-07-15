#include "main.h"
void GPIO_Init(void){
        GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2);
}

void Set_GPIO_on(uint32_t Port,uint32_t pin){
        GPIOPinWrite(Port, Port, Port);
}

