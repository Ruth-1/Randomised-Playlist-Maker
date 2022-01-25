//
// Created by Ruth on 16/03/2021.
//

#ifndef PLAYLIST2_INPUT_H
#define PLAYLIST2_INPUT_H
#include <stdio.h>
#include <stdbool.h>
#define FILE_LENGTH 100
#define LINE_LENGTH 100
struct playlist{
    char band[FILE_LENGTH];
    char song[FILE_LENGTH][FILE_LENGTH];
    int song_count;
    int band_count;
};
void initialize_arr(struct playlist record[]);
void read_file(FILE* fp,char store_file[][LINE_LENGTH],struct playlist record[]);
void readInput(char store_file[][LINE_LENGTH],struct playlist record[]);
void song_format(char store_file[][LINE_LENGTH], int size,struct playlist record[]);
#endif //PLAYLIST2_INPUT_H

