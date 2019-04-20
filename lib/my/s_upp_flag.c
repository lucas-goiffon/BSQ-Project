/*
** EPITECH PROJECT, 2018
** s_upp_flag.c
** File description:
** %S flag of my_printf
*/

#include "mylib.h"

int s_upp_flag(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar(92);
            count = count + octal_conversion(str[i]) + 1;
        } else {
            my_putchar(str[i]);
            count = count + 1;
        }
    }
    return (count);
}
