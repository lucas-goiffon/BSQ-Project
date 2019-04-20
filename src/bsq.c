/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main file of BSQ Project
*/

#include "../include/bsq.h"

char *replace_bsq(char *buff, bsq_t *bsq)
{
    bsq->square = bsq->square - 1;
    for (int lines = 0; lines < bsq->square; lines = lines + 1) {
        for (int i = 0; i < bsq->square; i = i + 1) {
            buff[bsq->ok] = 'x';
            bsq->ok = bsq->ok + 1;
        }
        bsq->ok = bsq->ok + bsq->lsize + 1 - bsq->square;
    }
    return (buff);
}

void find_bsq(char *buff, int i, bsq_t *bsq)
{
    bsq->fail = 0;
    bsq->count = 0;
    bsq->lines = 0;
    while (bsq->lines < bsq->square && bsq->fail == 0) {
        test_line(buff, i, bsq);
        if (bsq->count == bsq->square){
            i = i + bsq->lsize + 1;
            bsq->count = 0;
            bsq->lines = bsq->lines + 1;
        } else
            bsq->fail = 1;
    }
    if (bsq->fail == 0) {
        bsq->square = bsq->square + 1;
        find_bsq(buff, bsq->stock, bsq);
        bsq->ok = bsq->stock;
    }
}

void test_line(char *buff, int i, bsq_t *bsq)
{
    for (int x = 0; x < bsq->square; x = x + 1) {
        if (buff[i] == '.')
            bsq->count = bsq->count + 1;
        i = i + 1;
    }
}

int main(int ac, char **av)
{
    bsq_t bsq;
    char *buff = open_and_read(ac, av, &bsq.buff_size, &bsq.lsize);
    int i = 0;

    bsq.square = 1;
    bsq.end = 0;
    if (errors(buff, bsq) > 0)
        return (84);
    while (buff[i] != '\0' && bsq.end == 0) {
        if (buff[i] == '.') {
            bsq.stock = i;
            find_bsq(buff, i, &bsq);
        }
        i = i + 1;
    }
    buff = replace_bsq(buff, &bsq);
    my_printf("%s", buff);
    free(buff);
    return (0);
}