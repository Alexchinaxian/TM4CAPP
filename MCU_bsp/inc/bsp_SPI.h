#ifndef MCU_BSP_INC_BSP_SPI_H_
#define MCU_BSP_INC_BSP_SPI_H_
bool g_breceiveFlag ;
void SSI2_Init(void);
void SSI2IntHandler(void);
void vSPI_Receive(uint8_t *ucp_Data, uint16_t us_Size);
void vSPI_Transmit(uint8_t *ucp_Data, uint16_t us_Size);
uint8_t ucSPI_RW(uint8_t uc_SendData);
#endif
