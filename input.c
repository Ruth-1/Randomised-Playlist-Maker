//
// Created by Ruth on 16/03/2021.
//
#include "input.h"//takes functions from this header
#include <stdio.h>//used for functions such as printf
#include <string.h>//used for string manipulations
#include <stdbool.h>//used for booleans

//used to initialize struct with blank spaces
void initialize_arr(struct playlist record[]){
    for (int k = 0; k < FILE_LENGTH; k++) {
        strcpy(record[k].band,"");
        for (int j = 0; j < FILE_LENGTH; j++) {
            strcpy(record[k].song[j], "");
        }
    }
}

//reads from file,stores songs and artists into array of struct
void read_file(FILE *fp,char store_file[][LINE_LENGTH],struct playlist record[]) {
    initialize_arr(record);
    int i = 0;
    if (fp){
        while (!feof(fp) && i < FILE_LENGTH) {
            fgets(store_file[i], LINE_LENGTH, fp);
            if (store_file[i][strlen(store_file[i]) - 1] == '\n') {
                store_file[i][strlen(store_file[i]) - 1] = '\0';
                //if the last character in a line is a newline character, replace it with a null character
            }
            i++;
            //reads from file,stores each line in a 2D array until end of file is reached
        }
        //close file once txt is all in 2D array
        fclose(fp);
    }
    song_format(store_file,i,record);//reformat char array into struct
}

void song_format(char store_file[][LINE_LENGTH], int size,struct playlist record[]){
        int max_lines = size;
        //initialize record before storing strings into it
        initialize_arr(record);

        //variables used in comparing and storing 2D array in struct
        int f = 0, j = 0, k = 0, num_bands = 0;
        //f is used to index each array according to the number of bands
        //j is used to index the songs for each band
        //k is used to go index through our original store_file array
        char checker[FILE_LENGTH];
        while (k < max_lines){
            //loops until we have gone though all of store_file
            //copy the string from store_file into checker for convenience
            strcpy(checker, store_file[k]);
            if (!(strcmp(checker, "\n") == 0 || strcmp(checker, "\r\n") == 0 || strstr(checker, "***"))) {
                //checks if strings is not a newline or a song then copies it to struct.band
                strcpy(record[f].band, checker);
                k++;
                //once it's copied we then move on to the next line in store_file
                num_bands++;
                //increment the number of artists found so far
                record[0].band_count++;
                //store this value in struct.bandcount also
                strcpy(checker, store_file[k]);
                //then store the next string from store_file into checker
                j = 0;
                /*set the number of songs for this artist to 0 as we have yet to go to our while loop
                that checks for songs*/
            }

            while (strstr(checker, "***") != 0){
                //strstr is used to check if a certain string is contained in a different string -returns 1 if string is found
                //loop until we encounter a string that doesn't contain ***
                strcpy(record[f].song[j], checker);
                //copy the string into struct.songs
                k++;
                //go to next string in store_file and copy into checker
                strcpy(checker, store_file[k]);
                //increment the number of songs for the artist
                j++;
            }
            record[f].song_count = j;
            //store the number of songs found for artist f into struct.song_count one thw while loop is exited
            f++;
            //move to new array to hold information for next artist
            k++;
            //move to next line in store_file
        }
        //copy the number of bands into every array in the structure as this value will be the same for all of them
        for (int l = 0; l < num_bands; l++) {
            record[l].band_count = record[0].band_count;
        }
}
//reads from user,stores songs and artists into array of struct
void readInput(char store_file[][LINE_LENGTH],struct playlist record[]){
    bool check = true;
    initialize_arr(record);
    int i = 0;
    while(i < FILE_LENGTH && check) {
        fgets(store_file[i], LINE_LENGTH, stdin);
        if(strcmp(store_file[i], "0\n") == 0){
            //exist if user enters 0
            check = false;
        }
        //reads from keyboard,stores each line in a 2D array until user ends input with 0
        if (store_file[i][strlen(store_file[i]) - 1] == '\n') {
            store_file[i][strlen(store_file[i]) - 1] = '\0';
            //if the last character in a line is a newline character, replace it with a null character
        }
        i++;
    }
    song_format(store_file,i,record);//reformat char array into struct
}