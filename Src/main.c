#include "gd32f3x0.h"
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"

void idle_task(void *param)
{
    while (1)
    {
        gpio_bit_toggle(GPIOC, GPIO_PIN_13);
        vTaskDelay(500);
    }
}

int main(void)
{
    rcu_periph_clock_enable(RCU_GPIOC);
    gpio_mode_set(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO_PIN_13);
    gpio_output_options_set(GPIOC, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_13);
    gpio_bit_set(GPIOC, GPIO_PIN_13);
    xTaskCreate(idle_task, "idle_task", 128, NULL, 0, NULL);
    vTaskStartScheduler();
    while (1)
    {
    }
}
