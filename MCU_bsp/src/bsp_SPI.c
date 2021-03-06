#include "main.h"
void SPI_Init(void){
    SSI2_Init();
}
void SSI2IntHandler(void){
    uint32_t ui32Status;
    //读取 SSIMIS（SSI 屏蔽中断状态）。
    ui32Status = MAP_SSIIntStatus(SSI2_BASE, true);
    //清除 SSI 中断。
    MAP_SSIIntClear(SSI2_BASE, ui32Status);
    //关闭 RX FIFO 中断。
    MAP_SSIIntDisable(SSI2_BASE, SSI_RXFF);
    g_breceiveFlag = 1;
}

void SSI2_Init(void){
    //启用 SSI2使用。
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI2);
    //配置引脚PD0 PD1 PD2 PD3
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    MAP_GPIOPinConfigure(GPIO_PD1_SSI2XDAT0);
    MAP_GPIOPinConfigure(GPIO_PD0_SSI2XDAT1);
    MAP_GPIOPinConfigure(GPIO_PD2_SSI2FSS);
    MAP_GPIOPinConfigure(GPIO_PD3_SSI2CLK);

    /*
    为 SPI 主模式配置和启用 SSI2_BASE 端口。
    */
    MAP_GPIOPinTypeSSI(GPIO_PORTD_BASE,GPIO_PIN_0 |
                   GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3);
    MAP_SSIConfigSetExpClk(SSI2_BASE, g_ui32SysClock, SSI_FRF_MOTO_MODE_0,
                           SSI_MODE_MASTER, 2000000, 8); 
    //启用处理器中断。
    IntMasterEnable(); 
    //在 RX FIFO 满时启用 SSI1 中断。
    MAP_SSIIntEnable(SSI2_BASE, SSI_RXFF);
    // 在处理器 (NVIC) 上启用 SSI1 中断。
    IntEnable(INT_SSI2);
    //启用 SSI2模块。
    MAP_SSIEnable(SSI2_BASE);
}
/*
2022/07/16  Alex
name    : SSI2_RW
Function：SSI2 的读写函数
*/
uint8_t SSI2_RW(uint8_t Senddata){
    uint32_t Tempdate;
    uint8_t  ReceiveDate;
    //向SSI2 FIFO写入数据
    SSIDataPutNonBlocking(SSI2_BASE,Senddata);
    //等待SSI不忙
    while (SSIBusy(SSI2_BASE))
    {
        SSIDataGetNonBlocking(SSI2_BASE, &Tempdate);
    }
    //截取低八位数据
    ReceiveDate = Tempdate & 0xff;

    return ReceiveDate;    
}
/*
2022/07/16  Alex
name    : SSI2_Transmit
Function：SSI2发送函数
*/
void SSI2_Transmit(uint8_t *Senddata,uint16_t Size){
    uint16_t count;
    //写入连续数据
    for (count =0;count < Size; count++){
        SSI2_RW(Senddata[count]);
    }
}
/*
2022/07/16  Alex
name    : SSI2_Transmit
Function：SSI2发送函数
*/
void SSI2_Recive(uint8_t *ReceiveData,uint16_t size){
    uint16_t count;
    //连续读出数据
    for(count = 0; count < size; count++){
        ReceiveData[count] = SSI2_RW(0xFF);
    }
}

