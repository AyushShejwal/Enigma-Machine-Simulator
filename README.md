# Enigma-Machine-Simulator
Enigma Machine Simulator: A C/C++ command-line utility that emulates a simplified version of the historic Enigma Machine. This program allows encryption and decryption of files using a 2-rotor mechanism, supporting rotor configuration and various command-line options for seamless operation.

Files Included

rotorMachine.c: This file contains the actual implementation of the Enigma Machine. It includes functions responsible for the working of the enigma machine

rotorMachine.h: This header file contains function prototypes and any necessary declarations used in rotorMachine.c. It acts as an interface defining the functions implemented in rotorMachine.c.

config.rtr: Sample rotor configuration file.

Makefile: Build automation script.

rotors.ini: File storing rotor configurations.

test.txt, alice_test.txt- Sample inputs

lorem.txt Download lorem.txt(this file has \r characters in it)

lorU.txt Download lorU.txt(lorem.txt without \r characters)

shejwal_mainFile.c: The main file containing program logic.

Features
Command-line utility for encryption and decryption
Configurable through command-line arguments
Supports rotor configuration via file input
Encrypts/decrypts files using a 2-rotor mechanism
Usage
The program supports several command-line options:

To initialize rotor configuration:
./exe -i <configuration file>

To encrypt a file:
./exe -e <in file> <out file> -r <rotor 1 start> <rotor 2 start>

To decrypt a file:
./exe -d <in file> <out file> -r <rotor 1 start> <rotor 2 start>

Encrypt a file and set rotor configuration:
./exe -e <in file> <out file> -r <rotor 1 start> <rotor 2 start> -i <config file>

Decrypt a file and set rotor configuration:
./exe -d <in file> <out file> -r <rotor 1 start> <rotor 2 start> -i <config file>


Example File (test.txt):
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ABC DEF GHI JKL MNO PQR STU VWX YZ
ABC.DEF.GHI.JKL.MNO.PQR.STU.VWX.YZ

Encryption command:
./rotormachine -e test.txt test.enc -r 5 5

Encrypted File contents (test.enc):
MLKJIHGFEDCBA. ZYXWVUTSRQP
ZYRMLKFGFEGSRQSCBAWA. U. ZRYXWRYX
RQPQONM ONMMWVUNDCBLBA.NHGFSLKJQBA

Decryption command:
./rotormachine -d test.enc test.dec -r 5 5

Encrypted File contents (test.dec):
ABCDEFGHIJKLMNOPQRSTUVWXYZ
ABC DEF GHI JKL MNO PQR STU VWX YZ
ABC.DEF.GHI.JKL.MNO.PQR.STU.VWX.YZ

