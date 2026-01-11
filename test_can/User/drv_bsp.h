/**
 * @file drv_bsp.h
 * @brief RoboMaster 开发板 C 型板级支持包头文件 (纯C版本)
 */

#ifndef DRV_BSP_H
#define DRV_BSP_H

/* Includes ------------------------------------------------------------------*/
#include "main.h" // 确保包含HAL库头文件

/* Exported macros -----------------------------------------------------------*/

// C型板只有一路电源输出，我们将 LU, LD, RU, RD 全部映射到同一个位，或只使用 LU
#define BSP_DC24_LU_ON 0x00000001
#define BSP_DC24_LD_ON 0x00000002
#define BSP_DC24_RU_ON 0x00000004
#define BSP_DC24_RD_ON 0x00000008

// C型板 RGB LED 宏定义
#define BSP_LED_R_ON   0x00000010
#define BSP_LED_G_ON   0x00000020
#define BSP_LED_B_ON   0x00000040

// 兼容 A板的流水灯宏（在C板上无实际硬件，仅为编译不报错）
#define BSP_LED_1_ON   0x00000100
#define BSP_LED_2_ON   0x00000200
#define BSP_LED_3_ON   0x00000400
#define BSP_LED_4_ON   0x00000800
#define BSP_LED_5_ON   0x00001000
#define BSP_LED_6_ON   0x00002000
#define BSP_LED_7_ON   0x00004000
#define BSP_LED_8_ON   0x00008000

/* Exported types ------------------------------------------------------------*/

typedef enum {
    BSP_DC24_Status_DISABLED = GPIO_PIN_RESET,
    BSP_DC24_Status_ENABLED = GPIO_PIN_SET
} Enum_BSP_DC24_Status;

typedef enum {
    BSP_LED_Status_DISABLED = GPIO_PIN_RESET,
    BSP_LED_Status_ENABLED = GPIO_PIN_SET
} Enum_BSP_LED_Status;

/* Exported functions prototypes ---------------------------------------------*/

/**
 * @brief 初始化全部板级支持包引脚
 * @note 注意：C语言不支持默认参数，调用时必须传满 3 个参数
 */
void BSP_Init(uint32_t Status, float IMU_Heater_Rate, float Buzzer_Rate);

// 电源控制函数 (在.c中已映射至PH11)
void BSP_DC24_LU(Enum_BSP_DC24_Status Status);
void BSP_DC24_LD(Enum_BSP_DC24_Status Status);
void BSP_DC24_RU(Enum_BSP_DC24_Status Status);
void BSP_DC24_RD(Enum_BSP_DC24_Status Status);

// LED控制函数
void BSP_LED_R(Enum_BSP_LED_Status Status);
void BSP_LED_G(Enum_BSP_LED_Status Status);
void BSP_LED_B(Enum_BSP_LED_Status Status);

// 兼容性占位函数
void BSP_LED_1(Enum_BSP_LED_Status Status);
void BSP_LED_2(Enum_BSP_LED_Status Status);
void BSP_LED_3(Enum_BSP_LED_Status Status);
void BSP_LED_4(Enum_BSP_LED_Status Status);
void BSP_LED_5(Enum_BSP_LED_Status Status);
void BSP_LED_6(Enum_BSP_LED_Status Status);
void BSP_LED_7(Enum_BSP_LED_Status Status);
void BSP_LED_8(Enum_BSP_LED_Status Status);

#endif

/************************ COPYRIGHT(C) USTC-ROBOWALKER **************************/