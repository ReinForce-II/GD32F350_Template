/*!
    \file  main.c
    \brief led spark with systick, USART print and key example
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-06, V1.0.0, firmware for GD32F3x0
*/

#include "gd32f3x0.h"
#include "systick.h"
#include <stdio.h>
#include "main.h"
#include "gd32f3x0_eval.h"

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    /* configure systick */
    systick_config();
    /* initilize the LEDs, USART and key */
    gd_eval_led_init(LED1);
    gd_eval_com_init(EVAL_COM1);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    /* print out the clock frequency of system, AHB, APB1 and APB2 */
    printf("\r\nCK_SYS is %d", rcu_clock_freq_get(CK_SYS));
    printf("\r\nCK_AHB is %d", rcu_clock_freq_get(CK_AHB));
    printf("\r\nCK_APB1 is %d", rcu_clock_freq_get(CK_APB1));
    printf("\r\nCK_APB2 is %d", rcu_clock_freq_get(CK_APB2));

    rcu_ckout_config(RCU_CKOUTSRC_CKSYS, RCU_CKOUT_DIV1);
    while (1)
    {
        gd_eval_led_toggle(LED1);
        delay_1ms(500);
    }
}

/* retarget the C library printf function to the USART */
int __io_putchar(int ch)
{
    usart_data_transmit(EVAL_COM1, (uint8_t)ch);
    while (RESET == usart_flag_get(EVAL_COM1, USART_FLAG_TBE))
        ;

    return ch;
}

int _write(int fd, const void *buf, size_t count)
{
    for (int i = 0; i < count; i++)
    {
        __io_putchar(((uint8_t *)buf)[i]);
    }
    return count;
}
int _read(int fd, const void *buf, size_t count)
{
    return count;
}
