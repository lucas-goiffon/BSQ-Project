/*
** EPITECH PROJECT, 2018
** bsq.h
** File description:
** Definitions for bsq
*/

#ifndef BSQ_H_
#define BSQ_H_

#include "../lib/my/mylib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct declaration_t {
    int square;
    int end;
    int ok;
    int count;
    int stock;
    int fail;
    int buff_size;
    int lines;
    int lsize;
} bsq_t;

/* src/bsq.c */
char *replace_bsq(char *buff, bsq_t *bsq);
void find_bsq(char *buff, int i, bsq_t *bsq);
void test_line(char *buff, int i, bsq_t *bsq);

/* src/open_and_read.c */
char *read_file(int fd, int buff_size, int *lsize);
char *open_and_read(int ac, char **av, int *bs, int *lsize);
int set_buff_size(int fd);
void set_lsize(int fd, int *lsize);

/* src/error_management.c */
int errors(char *buff, bsq_t bsq);
int errors_two(char *buff, bsq_t bsq, int *r, int i);

#endif