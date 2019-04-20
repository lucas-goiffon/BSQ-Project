/*
** EPITECH PROJECT, 2019
** MyGit
** File description:
** error_management
*/

#include "../include/bsq.h"

int errors(char *buff, bsq_t bsq)
{
    int r = 0;
    int ligns = 0;
    int columns = 0;

    if (buff == NULL) {
        write(2, "Read fail\n", 10);
        return (84);
    }
    for (int i = 0; buff[i] != '\0'; i = i + 1) {
        ligns = errors_two(buff, bsq, &r, i);
    }
    if (r > 0 || ligns != bsq.buff_size) {
        write(2, "Invalid map\n", 12);
        return (84);
    }
    return (0);
}

int errors_two(char *buff, bsq_t bsq, int *r, int i)
{
    static int ligns = 0;
    static int columns = 0;

    columns = columns + 1;
    if (buff[i] == '\n') {
        ligns = ligns + 1;
        if ((columns - 1) != bsq.lsize)
            *r = *r + 1;
        columns = 0;
    } else if (buff[i] != '.' && buff[i] != 'o' && buff[i] != '\n')
        *r = *r + 1;
    return (ligns);
}