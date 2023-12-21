/*
Author: Ayush Sunil Shejwal
Date: October 30, 2023
Description: This is the .h file which contains the prototype of all the functions. Basically this file tells the compiler about all the function 
*/

#pragma once
#include <stdio.h>

void buildIni(char *thefile);
void buildRotors(int[28], int[28]);
void rotateRotorRight(int[28]);
void rotateRotorLeft(int[28]);
void setRotor1(int[28], int);
void setRotor2(int[28], int);
int charToIndex(char);
char indexToChar(int);
void encryptFile(FILE*, FILE*, int rotor1[28], int rotor2[28]);
void decryptFile(FILE*, FILE*, int rotor1[28], int rotor2[28]);
