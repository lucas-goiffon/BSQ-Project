/*
** EPITECH PROJECT, 2019
** MyGit
** File description:
** open_and_read
*/

#include "../include/bsq.h"

char *read_file(int fd, int buff_size, int *lsize)
{
    int offset = 0;
    int len = 0;
    int llsize = *lsize;
    int size = buff_size * llsize + buff_size;
    char *buff = malloc(sizeof(char) * (size + 14));

    set_buff_size(fd);
    fill_str(buff, size + 14);
    read(fd, buff, size);
    buff[size] = '\0';
    return (buff);
}

char *open_and_read(int ac, char **av, int *bs, int *lsize)
{
    int buff_size = *bs;
    int fd;
    int size;
    char *buff;
    struct stat filestat;

    if (ac == 2) {
        fd = open(av[1], O_RDONLY);
        stat(av[1], &filestat);
        if (fd != -1 && filestat.st_size > 0) {
            buff_size = set_buff_size(fd);
            *bs = buff_size;
            set_lsize(fd, lsize);
            fd = open(av[1], O_RDONLY);
            buff = read_file(fd, buff_size, lsize);
            return (buff);
        } else
            return (NULL);
        close(fd);
    }
    return (NULL);
}

int set_buff_size(int fd)
{
    char c = 0;
    char *test = malloc(sizeof(char) * 11);
    int i = 0;
    int buff_size = 0;

    fill_str(test, 11);
    while (c != '\n') {
        read(fd, &c, 1);
        test[i] = c;
        i = i + 1;
    }
    buff_size = my_getnbr(test);
    free(test);
    return (buff_size);
}

void set_lsize(int fd, int *lsize)
{
    char c = 0;
    int i = 0;

    while (c != '\n') {
        read(fd, &c, 1);
        i = i + 1;
    }
    *lsize = i - 1;
    close(fd);
}