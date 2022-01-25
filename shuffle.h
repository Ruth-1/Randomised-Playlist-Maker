//
// Created by Ruth on 16/03/2021.
//

#ifndef PLAYLIST2_SHUFFLE_H
#define PLAYLIST2_SHUFFLE_H
#define FILE_LENGTH 100
#include "input.h"
#include <string.h>
#include "sorting.h"
#include <stdbool.h>
extern int artistcount;
extern int structsize;
//struct declarations
struct format{
    int song_ID;
    char song[FILE_LENGTH];
    char times[FILE_LENGTH];
    char band[FILE_LENGTH];
    int min;
    int sec;
};
struct shuffle_struct{
    char s_song[FILE_LENGTH];
    char s_times[FILE_LENGTH];
    char s_band[FILE_LENGTH];

};
void format_songs(struct playlist arr[],struct format arr2[]);
void shuffle_songs(struct format arr2[], struct shuffle_struct shuf[]);
bool checker(struct shuffle_struct shuf[],int index);
void move(struct shuffle_struct shuf[],int index);
void print_shuffled(struct  shuffle_struct shuf[], int size);
#endif //PLAYLIST2_SHUFFLE_H

