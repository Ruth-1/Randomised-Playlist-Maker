//
// Created by Ruth on 16/03/2021.
//

#include "shuffle.h"
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
int artistcount = 0;
int structsize=0;
//global variables used to hold number of total songs and the number of artists
void format_songs(struct playlist arr[],struct format arr2[]) {
    char *tok;
    char checker[FILE_LENGTH];
    int j,l=0;
    //creates a new array of structs that holds artist songs and song duration

    for(int i = 0;i<arr[0].band_count;i++){
        artistcount= arr[0].band_count;
        for(j=0; j<arr[i].song_count;j++){
            //strcpy(checker,arr[i].band);
            arr2[l].song_ID = i;
            strcpy(arr2[l].band,arr[i].band);
            strcpy(checker,arr[i].song[j]);
            //use strkok to split songs and song duration
            tok = strtok(checker, "***");
            strcpy(arr2[l].song, tok);
            tok = strtok(NULL, "***");
            strcpy(arr2[l].times, tok);
            strcpy(checker,arr2[l].times);
            //use atoi to convert string numbers to integer numbers and store values to min and secs
            tok = strtok(checker,":");
            arr2[l].min = atoi(tok);
            tok = strtok(NULL, ":");
            arr2[l].sec = atoi(tok);
            l++;
        }
    }
    //store the value of the size of the new struct
    structsize = l;
}
//outputs shuffled playlist
void shuffle_songs(struct format arr2[], struct shuffle_struct shuf[]){
    srand(time(NULL));
    int array[artistcount];
    int songcounter[structsize];
    //initialize array songcounter to 1
    //used to keep check if a song has already been played
    for(int i = 0;i<structsize;i++){
        songcounter[i]=1;
    }
    //initialize array of size band_count to 3
    //used to keep track of the number of songs of an artist that are played
    for(int i = 0;i<artistcount;i++){
        array[i]=3;
    }
    //initialize shuf struct with blanks
    for(int i = 0;i<structsize;i++){
        strcpy(shuf[i].s_band,"");
        strcpy(shuf[i].s_song,"");
        strcpy(shuf[i].s_times,"");
    }
    //initialize variables to 0
    int time= 0;
    //used to randomly generate an index for j
    int i = (structsize) - 1,j;
    int k = 0;
    int minutes = 0;
    int seconds=0;
    //loop while time is not over 1 hour
    while(time <= 3599) {
        j = rand() % (i);
       //put into our new array the songs that meet the criteria - ie if they are not already in the playlist
       // or if they are not the fourth song from the same artist
        if ((songcounter[j] > 0) && (array[arr2[j].song_ID] > 0)) {
            //copy into new struct the randomly generated struct array
            strcpy(shuf[k].s_song, arr2[j].song);
            strcpy(shuf[k].s_band, arr2[j].band);
            strcpy(shuf[k].s_times, arr2[j].times);
            //decrement number of songs of the artist played
            array[arr2[j].song_ID]--;
            songcounter[j]--;
            //add new minutes to minutes variable
            minutes += arr2[j].min;
            //add new seconds to seconds variable
            seconds += arr2[j].sec;
            //if the seconds are over 60 add 1 to minutes
            minutes += seconds / 60;
            //set seconds equal to the remainder of this division
            seconds = seconds % 60;
            //add the time of the new stuct time value in seconds to time variable
            time += (arr2[j].min * 60) + arr2[j].sec;
            //move to next spot in struct
            k++;
        }
    }
    //once my array is filled I check if any artist has 3 songs in a row, if it does I shuffle the playlist using the
    //Fisher Yates Shuffle
    while(checker(shuf,k)){
        move(shuf,k);
    }
    //call function to print randomised playlist in correct format
    print_shuffled(shuf,k);
    printf("Total duration : %d:%.2d\n",minutes,seconds);
}
//checks if 3 songs of the same artist are playing in succession
bool checker(struct shuffle_struct shuf[],int index){
    for(int i = 1;i<index;i++){
        if (strcmp(shuf[i].s_band,shuf[i-1].s_band) == 0){
            if(strcmp(shuf[i-1].s_band,shuf[i+1].s_band) == 0) {
                if(strcmp(shuf[i].s_band,shuf[i+1].s_band) == 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

//prints out array in the specified format
void print_shuffled(struct shuffle_struct shuf[] ,int size){
    for (int m = 0; m < size; m++) {
        printf("%s: \"%s\" (%s)\n", shuf[m].s_band, shuf[m].s_song, shuf[m].s_times);

    }
}
//function to shuffle an array of songs
void move(struct shuffle_struct shuf[],int index){
    srand(time(NULL));
    int i, j;
    struct shuffle_struct temp = {"","",""};
    for (i = index - 1;  i > 0; i--)
    {
        j = rand() % (i);
        temp = shuf[i];
        shuf[i]=shuf[j];
        shuf[j] = temp;
    }
}