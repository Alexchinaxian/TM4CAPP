#include "main.h"
void GPIO_Init(void){
        GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, GPIO_PIN_2);
}

void Set_GPIO_On(uint32_t Port,uint32_t pin){
        GPIOPinWrite(Port, Port, Port);
}

void Set_GPIO_Off(uint32_t Port,uint32_t pin){
        GPIOPinWrite(Port, Port, Port);
}
