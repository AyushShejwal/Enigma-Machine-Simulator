/*
Author: Ayush Sunil Shejwal
Date: October 30, 2023
Description: This file contains all the functions required to run the encryption and the decryption 
*/


#include "rotorMachine.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

void buildIni(char *filename){          //The buildIni function that takes in values from the configFile XOR's it with the value 42 and writes them into rotors.ini
FILE *configFile;                       // makes configFile
FILE *rotorsIni;                        // makes rotorIni file
int value;

configFile = fopen(filename, "r");      // opens filename for reading and stores it in configFile
if (configFile == NULL){                // Prints error if the file is null and terminates the code using exit(1)
        perror("Error opening the configuration file");
        exit(1);
}

rotorsIni = fopen("rotors.ini", "w");   //opens the rotorsIni file for writing
if (rotorsIni == NULL){                 // Prints error if the file doesn't opne for writing and terminates the code using exit(1)
        perror("Error opening rotors.ini for writing");
        exit(1);
}

while (fscanf(configFile, "%d", &value) == 1){          // while loop that reads values from the configFile             
        int encryptedValue = value ^ 42;                //each value read is encrypted as XOR with the value 42 and stored in encryptedValue variable
        fprintf(rotorsIni, "%d\n", encryptedValue);     //prints the encrypted value in the rotorIni file
}

fclose(configFile);     //closes the configFile (good practice)
fclose(rotorsIni);      //closes the rotorsini File
}


void buildRotors(int rotor1[28],int rotor2[28]){        //function for buiding the two rotors
FILE *rotorsIni = fopen("rotors.ini", "r");             //opens the rotors.ini for writing

if (rotorsIni == NULL){         //prints error and terminates the program if the file is NULL
        perror("Error opening the rotors.ini file");
        exit(1);
}

int value;
int i = 0;

while(fscanf(rotorsIni,"%d", &value) == 1){     //while loop that scans each value from the rotorsIni
        value = value ^ 42;                     //decryptes the value using XOR with value 42
        if (i<28){                              // adds the first 28 values from the rotorsini to rotor1
                 rotor1[i] = value;}
        else {                                  // adds the next 28 values in the rotor2
                rotor2[i-28] = value;}
        i++;}
fclose(rotorsIni);}                             // closes rotorsIni (Good practice :) )

void rotateRotorRight (int rotor[28]){          //function for rotating the rotor to right by a value
        int ayush = rotor[27];
        for (int i = 27; i > 0; i--){
        rotor[i] = rotor[i -1];}
        rotor[0] = ayush;}

void rotateRotorLeft (int rotor[28]){           //function for rotating the rotor to left by a value
        int ayushi = rotor[0];
        for (int i = 0; i<27; i++){
        rotor[i] = rotor[i+1];}
        rotor[27] = ayushi;}

void setRotor1 (int rotor[28], int rotations){  //sets the rotor1 position by rotating the rotor by rotations value
        for (int i = 0; i< rotations; i++){
        rotateRotorRight(rotor);}}

void setRotor2 (int rotor[28], int rotations){  //sets the rotor2 position by rotating the rotor by rotations value
        for (int i = 0; i< rotations; i++){
        rotateRotorLeft(rotor);}}

int charToIndex(char convert){                  //function for converting the character to index value
        convert = toupper(convert);

        if (convert == ' '){                    //stores ' ' as value 26
        return 26;}
        else if (convert == '.'){               //stores '.' as value 27
        return 27;}
        else if (convert >= 'A' && convert <= 'Z'){
        return convert - 'A';}                  //converts the convert(character in uppercase) to index using ASCII values
        else { return -1; }}

char indexToChar(int index){                    //converts the index value to character
        if (index == 26){
        return ' ';}
        else if (index == 27){
        return '.';}
        else if (index >= 0 && index <= 25){
        return (char)(index + 'A');}
        else { return '?';} }

void encryptFile(FILE *infile, FILE *outfile, int rotor1[28], int rotor2[28]){          //function for encrypting an entire file
        char ayushs[256];                                                               //defines a character array
        while (fgets(ayushs, sizeof(ayushs), infile)!=NULL){                            //while loop that takes in a line from the input file once every loop
        for (int i=0;i< strlen(ayushs) ; i++) {                                         //for loop from i=0 to length of ayushs(line) -1
        char originalChar = ayushs[i];                                                  //stores character from ayushs line (starting at i = 0)
        int index = charToIndex(originalChar);                                          //converts that character to index and stores it in index integer

        if (ayushs[i] == '\n'){                                                         //if newline character found, continues to the next for loop
        continue;}

        if (index != -1){                                                               //stores the value at that index in the rotor1 in an integer place
        int place = rotor1[index];

        int z;
        for (int j = 0; j<28; j++){                                                     // second for loop that iterates through rotor2 and finds the index where place exists and stores that index in z
        if (place == rotor2[j]){
                z = j;}}

        char encryptedChar = indexToChar(z);                                            //converts that z (index of value in rotor2) into charcter using indexToChar function and stores it in encryptedChar
        ayushs[i] = encryptedChar;                                                      //stores encryptedChar in the ayushs array in the i index
        }rotateRotorRight(rotor1);                                                      //rotates both the rotors as single encryption is done
        rotateRotorLeft(rotor2);
}
        fputs(ayushs, outfile);                                                         //puts the whole line got by ayushs into outfile
}}

void decryptFile(FILE *infile, FILE *outfile, int rotor1[28], int rotor2[28]){          //function for decrypting an entire file
        char sanvi[256];                                                                //defines a character array
        while (fgets(sanvi, sizeof(sanvi), infile)!=NULL){                              //while loop that takes in a line from the input file once every loop
        for (int i=0;i< strlen(sanvi) ; i++) {                                          //for loop from i=0 to length of sanvi(line) -1
        char originalChar = sanvi[i];                                                   //stores character from sanvi line (starting at i = 0)
        int index = charToIndex(originalChar);                                          //converts that character to index and stores it in index integer

        if (sanvi[i] == '\n'){                                                          //if newline character found, continues to the next for loop 
        continue;}

        if (index != -1){                                                               //stores the value at that index in the rotor2 in an integer place
        int place = rotor2[index];

        int z;
        for (int j = 0; j<28; j++){                                                     //second for loop that iterates through rotor1 and finds the index where place exists and stores that index in z
        if (place == rotor1[j]){
                z = j;}}

        char decryptedChar = indexToChar(z);                                            //converts that z (index of value in rotor1) into character using indexToChar function and stores it in decryptedChar
        sanvi[i] = decryptedChar;                                                       //stores decryptedChar in the sanvi array in the i index
        }rotateRotorRight(rotor1);                                                      //rotates both the rotors as single decryption is done
        rotateRotorLeft(rotor2);
}
        fputs(sanvi, outfile);                                                          //puts the whole line got by sanvi into outfile
}}

