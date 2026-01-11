/**
 * @file drv_bsp.c
 * @brief RoboMaster 开发板 C 型板级支持包 (适配自 A 板代码)
 */

#include "drv_bsp.h"

/**
 * @brief 初始化全部板级支持包引脚
 */
void BSP_Init(uint32_t Status, float IMU_Heater_Rate, float Buzzer_Rate)
{
    // C 型板只有一路电源输出，通常对应原来的 LU (左上) 控制逻辑
    BSP_DC24_LU((Enum_BSP_DC24_Status)((Status & BSP_DC24_LU_ON) == 0 ? BSP_DC24_Status_DISABLED : BSP_DC24_Status_ENABLED));

    // C 型板板载 RGB LED 控制
    BSP_LED_R((Enum_BSP_LED_Status)((Status & BSP_LED_R_ON) == 0 ? BSP_LED_Status_DISABLED : BSP_LED_Status_ENABLED));
    BSP_LED_G((Enum_BSP_LED_Status)((Status & BSP_LED_G_ON) == 0 ? BSP_LED_Status_DISABLED : BSP_LED_Status_ENABLED));
    // 如果你的 h 文件定义了 LED_B_ON，取消下面注释
    // BSP_LED_B((Enum_BSP_LED_Status)((Status & BSP_LED_B_ON) == 0 ? BSP_LED_Status_DISABLED : BSP_LED_Status_ENABLED));
}

/**
 * @brief 电源输出控制 (核心 PMOS 引脚)
 */
void BSP_DC24_LU(Enum_BSP_DC24_Status Status)
{
    // C 型板 PMOS 控制引脚为 PH11
    // 高电平导通输出，同时绿灯亮起
    HAL_GPIO_WritePin(GPIOH, GPIO_PIN_11, (GPIO_PinState)Status);
}

/**
 * @brief 红色 LED (PH12)
 */
void BSP_LED_R(Enum_BSP_LED_Status Status)
{
    HAL_GPIO_WritePin(GPIOH, GPIO_PIN_12, (GPIO_PinState)Status);
}

/**
 * @brief 绿色 LED (PH11)
 */
void BSP_LED_G(Enum_BSP_LED_Status Status)
{
    HAL_GPIO_WritePin(GPIOH, GPIO_PIN_11, (GPIO_PinState)Status);
}

// 保持 A 板兼容性的空函数
void BSP_DC24_LD(Enum_BSP_DC24_Status Status) {}
void BSP_DC24_RU(Enum_BSP_DC24_Status Status) {}
void BSP_DC24_RD(Enum_BSP_DC24_Status Status) {}
void BSP_LED_1(Enum_BSP_LED_Status Status) {}
void BSP_LED_2(Enum_BSP_LED_Status Status) {}
void BSP_LED_3(Enum_BSP_LED_Status Status) {}
void BSP_LED_4(Enum_BSP_LED_Status Status) {}
void BSP_LED_5(Enum_BSP_LED_Status Status) {}
void BSP_LED_6(Enum_BSP_LED_Status Status) {}
void BSP_LED_7(Enum_BSP_LED_Status Status) {}
void BSP_LED_8(Enum_BSP_LED_Status Status) {}