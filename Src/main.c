/*!
    \file  main.c
    \brief led spark with systick, USART print and key example
*/

/*
    Copyright (C) 2017 GigaDevice

    2017-06-06, V1.0.0, firmware for GD32F3x0
*/

#include "main.h"
#include "gd32f3x0.h"
#include "gd32f3x0_eval.h"
#include "systick.h"
#include <stdio.h>

int main(void)
{
    /* configure systick */
    systick_config();
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    while (1) {
    }
}
