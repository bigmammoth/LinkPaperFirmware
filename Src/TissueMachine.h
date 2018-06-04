#ifndef _TISSUE_MACHINE_H
#define _TISSUE_MACHINE_H

#include <stm32f1xx.h>
#include <string.h>
#include <stdbool.h>
#include "stm32f1xx_hal.h"

#define TISSUE_MACHINE_RX_BUFF_LEN	4
#define TISSUE_MACHINE_TX_BUFF_LEN	3

void uart3Init(void);
void uart3Receive(void);
void sendControl2TissueMachine(char*);

// 切纸机数据含义
// 上传数据
static const char MACHINE_START [TISSUE_MACHINE_RX_BUFF_LEN] = 		{0x45, 0x30, 0x31, 0x47};

static const char GIVE_LEN_15CM [TISSUE_MACHINE_RX_BUFF_LEN] = 		{0x45, 0x30, 0x4D, 0x47};
static const char GIVE_LEN_60CM [TISSUE_MACHINE_RX_BUFF_LEN] = 		{0x45, 0x31, 0x42, 0x47};
static const char GIVE_LEN_80CM [TISSUE_MACHINE_RX_BUFF_LEN] = 		{0x45, 0x31, 0x44, 0x47};
static const char GIVE_LEN_100CM [TISSUE_MACHINE_RX_BUFF_LEN] = 	{0x45, 0x31, 0x46, 0x47};

static const char TISSUE_EMPTY [TISSUE_MACHINE_RX_BUFF_LEN] = 		{0x45, 0x34, 0x31, 0x47};
static const char TISSUE_JAM [TISSUE_MACHINE_RX_BUFF_LEN] = 		{0x45, 0x35, 0x31, 0x47};

static const char TISSUE_LEN_60CM [TISSUE_MACHINE_RX_BUFF_LEN] = 	{0x45, 0x36, 0x31, 0x47};
static const char TISSUE_LEN_80CM [TISSUE_MACHINE_RX_BUFF_LEN] = 	{0x45, 0x37, 0x31, 0x47};
static const char TISSUE_LEN_100CM [TISSUE_MACHINE_RX_BUFF_LEN] = 	{0x45, 0x38, 0x31, 0x47};

static const char TISSUE_FULL [TISSUE_MACHINE_RX_BUFF_LEN] = 		{0x45, 0x4F, 0x4D, 0x47};

// 切纸机数据含义
// 下发数据
static const char CUT_TISSUE [TISSUE_MACHINE_TX_BUFF_LEN] = 		{0x45, 0x31, 0x47};

static const char SET_LEN_60CM [TISSUE_MACHINE_TX_BUFF_LEN] = 		{0x45, 0x36, 0x47};
static const char SET_LEN_80CM [TISSUE_MACHINE_TX_BUFF_LEN] = 		{0x45, 0x37, 0x47};
static const char SET_LEN_100CM [TISSUE_MACHINE_TX_BUFF_LEN] = 		{0x45, 0x38, 0x47};

#endif /* _TISSUE_MACHINE_H */
