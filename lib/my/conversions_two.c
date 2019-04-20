/*
** EPITECH PROJECT, 2018
** conversions_two.c
** File description:
** Following of conversions.c
*/

#include <stdlib.h>
#include "mylib.h"
#include "conv.h"

int octal_conversion(unsigned long nb)
{
    conv;
    while (testsize > 0) {
        testsize = testsize / 8;
        char_size = char_size + 1;
    }
    str = malloc(sizeof(char) * (char_size + 1));
    str[char_size] = '\0';
    char_size = char_size - 1;
    if (nb == 0)
        str = "0\0";
    for (char_size; nb > 0; char_size = char_size - 1) {
        r = nb % 8;
        octal_conversion_two(r, str, char_size);
        nb = nb / 8;
    }
    my_putstr(str);
    count = my_strlen(str) - 2;
    free(str);
    return (count);
}

void octal_conversion_two(int r, char *str, int char_size)
{
    char *base = "01234567";

    str[char_size] = base[r];
}

int hexa_conversion_low(unsigned long nb)
{
    conv;
    while (testsize > 0) {
        testsize = testsize / 16;
        char_size = char_size + 1;
    }
    str = malloc(sizeof(char) * (char_size + 1));
    str[char_size] = '\0';
    char_size = char_size - 1;
    if (nb == 0)
        str = "0\0";
    for (char_size; nb > 0; char_size = char_size - 1) {
        r = nb % 16;
        hexa_conversion_low_two(r, str, char_size);
        nb = nb / 16;
    }
    my_putstr(str);
    count = my_strlen(str) - 2;
    free(str);
    return (count);
}

void hexa_conversion_low_two(int r, char *str, int char_size)
{
    char *base = "0123456789abcdef";

    str[char_size] = base[r];
}