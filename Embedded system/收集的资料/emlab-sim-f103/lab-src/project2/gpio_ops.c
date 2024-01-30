/*
 *      Author: ljp
 */

#ifdef STM32F407xx
#include "stm32f4xx_hal.h"
#endif
#ifdef STM32F10X_MD
#include "stm32f1xx_hal.h"
#endif
#include "stdio.h"


#define BIT_MASK_FROM_TO(n1, n2) (((unsigned) -1 >> (31 - (n2))) & ~((1U << (n1)) - 1))
/*lv[n1..n2] = val*/
#define BIT_RANGE_ASSIGN(reg, val, n1, n2) ((reg) = ((reg) & ~(BIT_MASK_FROM_TO((n1),(n2)))) | ((((val) << (n1)) & (BIT_MASK_FROM_TO((n1),(n2))))))


void leds_init(void) {
  GPIO_InitTypeDef GPIO_InitStruct;
  /* GPIO Ports Clock Enable */
#ifdef STM32F407xx
  __HAL_RCC_GPIOF_CLK_ENABLE();
#endif
#ifdef STM32F10X_MD
  __HAL_RCC_GPIOC_CLK_ENABLE();
#endif

  /*Configure GPIO pins : PF7 PF8 PF9 PF10 */
#ifdef STM32F407xx
  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10;
#endif
#ifdef STM32F10X_MD
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
#endif
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
#ifdef STM32F407xx
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
#endif
#ifdef STM32F10X_MD
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
#endif
}

////D6 - D9: PF7 - PF10
void led_set(unsigned int val) {
#ifdef STM32F407xx
    BIT_RANGE_ASSIGN(GPIOF->ODR, val, 7, 10);
#endif
#ifdef STM32F10X_MD
    BIT_RANGE_ASSIGN(GPIOC->ODR, val, 6, 9);
#endif
}


void keys_init(void) {
  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  
#ifdef STM32F407xx
  /*Configure GPIO pin : PI9 - K3*/
  __HAL_RCC_GPIOI_CLK_ENABLE();
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);

  /*Configure GPIO pin : PF11 - K4*/
  __HAL_RCC_GPIOF_CLK_ENABLE();
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pin : PC13 - K5*/
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  __HAL_RCC_GPIOC_CLK_ENABLE();
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA0 - K6*/
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  __HAL_RCC_GPIOA_CLK_ENABLE();
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
#endif
#ifdef STM32F10X_MD
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  __HAL_RCC_GPIOC_CLK_ENABLE();
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
#endif
}

#ifdef STM32F407xx

int k3_read(void) {
    return (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_9) == GPIO_PIN_SET);
}
int k4_read(void) {
    return (HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_11) == GPIO_PIN_SET);
}
int k5_read(void) {
    return (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_SET);
}
int k6_read(void) {
    return (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_SET);
}
#endif
#ifdef STM32F10X_MD
int k3_read(void) {
    return (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0) == GPIO_PIN_SET);
}
int k4_read(void) {
    return (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_1) == GPIO_PIN_SET);
}
int k5_read(void) {
    return (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_2) == GPIO_PIN_SET);
}
int k6_read(void) {
    return (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3) == GPIO_PIN_SET);
}
#endif
