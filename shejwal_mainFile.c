/*
Author: Ayush Sunil Shejwal
Date: October 30, 2023
Description: This file contains all the functions required to run the encryption and the decryption 
Usage: ./exe -i <configuration file>
./exe -e <in file> <out file> -r <rotor 1 start> <rotor 2 start>
./exe -d <in file> <out file> -r <rotor 1 start> <rotor 2 start>
./exe -e <in file> <out file> -r <rotor 1 start> <rotor 2 start> -i <config file>
./exe -d <in file> <out file> -r <rotor 1 start> <rotor 2 start> -i <config file>
*/

#include "rotorMachine.h"               //importing the .h file
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){

         if (strcmp(argv[1], "-i") == 0) {              //first f statement which basically checks for -i in the second place argument of the command line (i.e at argv[1]
        char *configFileName = argv[2];                 //extracts the configfile from argv[2] and saves it in configFileName
        buildIni(configFileName);}                      //calls the buildini function and passes configFileName as the argument


        else if ((strcmp(argv[1], "-e")) == 0) {        //checks for -e in the argv[1] of the command line
        if (argc < 7) {                                 // if the argc commands are less than 7, then throws an error
            printf("Invalid number of arguments for -e operation\n");
            return 1;
        }
        if (argc == 7){                                 //if the argc's are 7 i.e for handeling the case 2      
        char *inputFile = argv[2];                      //extracts inputfile from argv[2] and stores it in inputFileName
        char *outputFile = argv[3];                     //extracts outputfile from argv[3] and stores it in outputFileName
        int rotor1Start = atoi(argv[5]);                //extracts start position for rotor1
        int rotor2Start = atoi(argv[6]);                //extratcs start position for rotor2
        int rotor1[28];                                 //defines rotor1 array
        int rotor2[28];                                 //defines rotor2 array
        FILE *inFile = fopen(inputFile, "r");           //deines inFile and stores inputFile as read only
        FILE *outFile = fopen(outputFile, "w");         //defines outFile and stores outputFile for writing

        buildRotors(rotor1, rotor2);                    //calls buildRotors function passing the rotor1 and rotor2 as arguments
        setRotor1(rotor1, rotor1Start);                 //sets rotor1 in the position given 
        setRotor2(rotor2, rotor2Start);                 //sets rotor2 in the position given 
        encryptFile(inFile, outFile, rotor1, rotor2);   //calls the encryptFile to encrypt the inputfile
        fclose(inFile);                                 //closes the inFile (good practice)
        fclose(outFile);}                               //closes the outFile

        else{                                           // else, i.e if the argc != 7, then this loop works, i.e for case 4
        char *inputFile = argv[2];
        char *outputFile = argv[3];
        int rotor1Start = atoi(argv[5]);
        int rotor2Start = atoi(argv[6]);
        int rotor1[28];
        int rotor2[28];
        FILE *inFile = fopen(inputFile, "r");
        FILE *outFile = fopen(outputFile, "w");

        if (strcmp(argv[7], "-i") == 0){                // if statement that checks if -i exists in argv[7] position, if yes, thenn calls in the buildIni function
        char *configFileName = argv[8];
        buildIni(configFileName);}

        buildRotors(rotor1, rotor2);
        setRotor1(rotor1, rotor1Start);
        setRotor2(rotor2, rotor2Start);
        encryptFile(inFile, outFile, rotor1, rotor2);
        fclose(inFile);
        fclose(outFile);}}


        else if (strcmp(argv[1], "-d") == 0) {          // checks for -d in the argv[1]
        if (argc < 7) {
            printf("Invalid number of arguments for -e operation\n");
            return 1;
        }

        if (argc == 7){                                 //if the argc is 7, that is if the arguments are 7, this code snippet works, i.e for case 3
        char *inputFile = argv[2];
        char *outputFile = argv[3];
        int rotor1Start = atoi(argv[5]);
        int rotor2Start = atoi(argv[6]);
        int rotor1[28];
        int rotor2[28];
        FILE *inFile = fopen(inputFile, "r");
        FILE *outFile = fopen(outputFile, "w");

        buildRotors(rotor1, rotor2);
        setRotor1(rotor1, rotor1Start);
        setRotor2(rotor2, rotor2Start);
        decryptFile(inFile, outFile, rotor1, rotor2);
        fclose(inFile);
        fclose(outFile);}

        else {                                          // else if argv != 7, and still -d at argv[1], this is the code for case 5, that is decrypting with a config file
        if (strcmp(argv[7], "-i") == 0){
        char *configFileName = argv[8];
        buildIni(configFileName);}

        char *inputFileName = argv[2];
        char *outputFileName = argv[3];
        int rotor1Start = atoi(argv[5]);
        int rotor2Start = atoi(argv[6]);
        int rotor1[28];
        int rotor2[28];
        FILE *inFile = fopen(inputFileName, "r");
        FILE *outFile = fopen(outputFileName, "w");
        char *configFileName = argv[8];
        buildIni(configFileName);
        buildRotors(rotor1, rotor2);
        setRotor1(rotor1, rotor1Start);
        setRotor2(rotor2, rotor2Start);
        decryptFile(inFile, outFile, rotor1, rotor2);
        fclose(inFile);
        fclose(outFile);}}
        return 0;}
