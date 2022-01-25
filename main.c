#include <stdio.h>
#include "sorting.h"
#include "input.h"
#include "shuffle.h"
#define DEFAULT_INPUT_FILE "artistes+songs.txt"
//main uses functions from these header
int main(int argc, char*argv[]){
    FILE *fp;
    struct playlist record[FILE_LENGTH];
    struct format for_songs[FILE_LENGTH];
    struct shuffle_struct shuf_songs[FILE_LENGTH];
    //struct declarations
    char store_file[FILE_LENGTH][LINE_LENGTH] = {0};
    //array to store input
    /*Check if we have an argument.*/
    if (argc > 1) {
        if ((fp = fopen(argv[1], "r")) == NULL) {
            //check if file passed by user exists
            printf("%s does not exist or cannot be opened for reading.\n", argv[1]);
            return 1;
        } else {
            read_file(fp, store_file, record);
        }
    }
    else{
        //if no file is passed by user, try to open the default file
        //if no default file, then get input from keyboard
        if((fp = fopen(DEFAULT_INPUT_FILE, "r")) == NULL){
            printf("%s: No file found.\n", DEFAULT_INPUT_FILE);
            printf("Please input your text in the specified format:\n");
            printf("Enter 0 to end input:\n");
            readInput(store_file,record);//read from keyboard into a 2D array and then into a array of structs
        }
        else{
            read_file(fp,store_file,record);//read from file into a 2D array and then into a array of structs
        }

    }
    sortBands(record);//sorts artists
    sortSongs(record);//sorts songs according to each artist
    printSort(record);//prints out struct
    format_songs(record,for_songs);//write struct into a new array of structs with different format
    printf("Randomised Playlist:\n");
    shuffle_songs(for_songs,shuf_songs);//outputs a randomised playlist
    return 0;
   }
