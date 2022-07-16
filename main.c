#include "main.h"
int main(void)
{
    Time_Init();//时钟初始化
    UART_init();//串口初始化
    SPI_Init();//SPI初始化
}
