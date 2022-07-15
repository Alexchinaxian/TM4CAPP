#include "main.h"
int main(void)
{
    Time_Init();//时钟初始化
    UART_init();//串口初始化

    while(1){
        UART_IAP();
    }
}
