#ifndef MCU_BSP_INC_BSP_SPI_H_
#define MCU_BSP_INC_BSP_SPI_H_
bool g_breceiveFlag ;
void SPI_Init(void);
void SSI2_Init(void);
void SSI2IntHandler(void);
uint8_t SSI2_RW(uint8_t Senddata);
void SSI2_Transmit(uint8_t *Senddata,uint16_t Size);
void SSI2_Recive(uint8_t *ReceiveData,uint16_t size);
#endif
