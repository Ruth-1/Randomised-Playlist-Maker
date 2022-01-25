//
// Created by Ruth on 16/03/2021.
//
#include "sorting.h"
#include <string.h>//used for string manipulations
//function to sort bands that takes struct as argument
void sortBands(struct playlist arr[]){
    int i,j,num_bands;
    //initial struct array current which will be used to hold arrays as sort proceeds
    struct playlist current = {"","""",0,0};
    //assign the number of bands to a variable for convenience
    num_bands =  arr[0].band_count;
    //sorting:
    for(i = 0; i < num_bands; i++){
        j = i - 1;
        current = arr[i];
        while(j>= 0 && strcmp(current.band,arr[j].band) <0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
    //when sorting you compare artist names against each other but when moving them around you carry the entire array for that artist
}
void sortSongs(struct playlist arr[]){
    int i,j;
    int num_bands =  arr[0].band_count;
    char tmp[LINE_LENGTH];
    for(int m = 0; m < num_bands; m++){
        for(i = 0; i < arr[m].song_count; i++){
            //sort songs of the same artist(structure array)
            j = i - 1;
            strcpy(tmp, arr[m].song[i]);
            while(j>= 0 && strcmp(tmp,arr[m].song[j]) <0){
                strcpy(arr[m].song[j+1],arr[m].song[j]);
                j--;
            }
            strcpy(arr[m].song[j+1],tmp);
        }
    }
}

void printSort(struct playlist arr[]){
    //prints artists according to specified order and format
    int num_bands =  arr[0].band_count;
    for(int i =0;i<num_bands;i++){
        printf("%s\n", arr[i].band);
        for(int j=0;j<arr[i].song_count;j++){
            printf(" o %s\n" ,arr[i].song[j]);
        }
        puts("\n");
    }
}

