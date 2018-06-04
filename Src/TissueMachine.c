#include "TissueMachine.h"

extern UART_HandleTypeDef huart3;

// uart3 接收缓冲区
uint8_t uart3RxBuffer[TISSUE_MACHINE_RX_BUFF_LEN];

// 切纸机发过来的数据
char tissueMachineData[TISSUE_MACHINE_RX_BUFF_LEN];

// 发给切纸机的数据
char tissueMachineControl[TISSUE_MACHINE_TX_BUFF_LEN];

// 切纸机状态更新标志位
bool tissueStateUpdated = false;

/**
* @brief USART3 init function

* Serial communication between tissue machine and device MCU
* @param none
* @return none
*/
void uart3Init(void)
{
	HAL_UART_Receive_IT(&huart3, (uint8_t *)&uart3RxBuffer, TISSUE_MACHINE_RX_BUFF_LEN);//开启下一次接收中断 
}

/**
* @brief USART3 receive function

* Serial communication between tissue machine and device MCU
* @param none
* @return none
*/
void uart3Receive(void)
{
	memcpy(tissueMachineData, uart3RxBuffer, TISSUE_MACHINE_RX_BUFF_LEN);
	tissueStateUpdated = true;
	HAL_UART_Receive_IT(&huart3, (uint8_t *)&uart3RxBuffer, TISSUE_MACHINE_RX_BUFF_LEN);//开启下一次接收中断
}

/**
* @brief 发送命令到切纸机

* Serial communication between tissue machine and device MCU
* @param none
* @return none
*/
void sendControl2TissueMachine(char* command)
{
	HAL_UART_Transmit_IT(&huart3, (uint8_t*)command, TISSUE_MACHINE_TX_BUFF_LEN);
}
