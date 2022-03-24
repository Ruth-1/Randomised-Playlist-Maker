# Randomised-Playlist-Maker
Program that takes  a list of artiste’s names, their songs and song durations; sorts the songs and artistes as input and then prints a randomized playlist that sums up to /as close to an hour.

The program takes  input from a file specified as an argument to the program. If the file does not exists or is not readable, the program prints out an error message to this effect.

If no file is specifed, the program prompts the user to enter the artistes and songs information using a text based interface in a specified format.

The format of the file is as follows:

Artiste name Song titleSong duration Song titleSong duration ... Song titleSong duration Artiste name Song titleSong duration Song titleSong duration ... Song titleSong duration ...

Each song title comprises alphanumeric characters (letters, numbers and symbols) but does not contain the sub-string “***”. “Song duration” is in the form [m]m:ss, where [m]m denotes a one- or two-digit number of minutes and ss denotes a two-digit number of seconds. For testing purposes, at least two artistes should have three or more songs each.

The program sorts the input by artiste name and then by song title and prints it out in the following format:

Sorted list of artistes and songs Artiste name o Song titleSong duration o Song titleSong duration ... o Song titleSong duration Artiste name o Song titleSong duration o Song titleSong duration ... o Song titleSong duration


The program then generates a random playlist of the songs, according to the following constraints:

• An artiste cannot have more than two songs in a row 
• An artiste cannot have more than three songs in total in the playlist; 
• A song cannot appear twice in the playlist; 
• The total playlist length should be as close as possible to one hour. Specifically, the last song must start on or before 59:59. The randomised playlist and the total time should be printed out in the following format:

Randomised playlist Artiste name: "Song title" (Song duration) Artiste name: "Song title" (Song duration) ... Artiste name: "Song title" (Song duration) Total duration: .

An example input file is as follows: The National Fireproof2:58 Hard to Find4:13 England5:40 Son5:20 Light Years3:32 Lean4:31 The System Only Dreams in Total Darkness***3:56

Arcade Fire Rebellion (Lies)5:10 Wake Up5:39 Cold Wind***3:12 Neighborhood #1 (Tunnels)***4:48 Neighborhood #3 (Power Out)***5:12

The War on Drugs Under the Pressure8:51 Red Eyes4:58

Sufjan Stevens Go! Chicago! Go! Yeah!6:04 Chicago [To String Remix]5:32 Carrie & Lowell3:14 John My Beloved5:03

London Grammar Wasting My Young Years***3:24 Strong [Hackman remix]***5:13

Jos Gonzlez Heartbeats***2:40

Bon Iver 29 #Strafford APTS4:05 00000 Million3:53 re: Stacks***6:40

Future Islands Tin Man3:14 Seasons (Waiting on You)3:46 Grease4:35 Spirit4:22

Public Service Broadcasting They Gave Me A Lamp3:56 The Other Side6:20 Go!***4:13

The sorted input would be as follows:

Sorted list of artistes and songs Arcade Fire o Cold Wind***3:12 o Rebellion (Lies)***5:10 o Neighborhood #1 (Tunnels)***4:48 o Neighborhood #3 (Power Out)5:12 o Wake Up5:39

Bon Iver o 00000 Million3:53 o 29 #Strafford APTS4:05 o re: Stacks***6:40

Future Islands o Grease4:35 o Seasons (Waiting on You)3:46 o Spirit4:22 o Tin Man3:14

Jos Gonzlez o Heartbeats***2:40 London Grammar o Strong [Hackman remix]5:13 o Wasting My Young Years3:24

Public Service Broadcasting o Go!4:13 o The Other Side6:20 o They Gave Me A Lamp***3:56

Sufjan Stevens o Carrie & Lowell***3:14 o Chicago [To String Remix]***5:32 o Go! Chicago! Go! Yeah!6:04 o John My Beloved5:03

The National o England5:40 o Fireproof2:58 o Hard to Find4:13 o Lean4:31 o Light Years3:32 o Son5:20 o The System Only Dreams in Total Darkness***3:56

The War on Drugs o Red Eyes4:58 o Under the Pressure8:51

An example randomised playlist would be the following:

Randomised playlist Public Service Broadcasting: "They Gave Me A Lamp" (3:56) The War on Drugs: "Under the Pressure" (8:51) Future Islands: "Spirit" (4:22) Arcade Fire: "Cold Wind" (3:12) The National: "England" (5:40) Bon Iver: "re: Stacks" (6:40) Sufjan Stevens: "Chicago [To String Remix]" (5:32) Jos Gonzlez: "Heartbeats" (2:40) Public Service Broadcasting: "The Other Side" (6:20) Public Service Broadcasting: "Go!" (4:13) Arcade Fire: "Rebellion (Lies)" (5:10) London Grammar: "Wasting My Young Years" (3:24) Total duration: 60:00.
