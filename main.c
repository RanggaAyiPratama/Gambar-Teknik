/*
Nama: Rangga Ayi Pratama
Kelas: 1CF
*/

#include <reg51.h>
#include <stdio.h>

sbit Data1 = P1^0;
sbit Clock1 = P1^1;
sbit Load1 = P1^2;

sbit Data2 = P2^0;
sbit Clock2 = P2^1;
sbit Load2 = P2^2;

sbit Data3 = P3^0;
sbit Clock3 = P3^1;
sbit Load3 = P3^2;

void msdelay(unsigned int value){
	unsigned int x,y;
	for(x=0; x < value; x++){
		for(y=0;y<120;y++){
		}
	}
}

void displayInit(){
	Data1 = 0;
	Clock1 = 0;
	Load1 = 0;
	Data2 = 0;
	Clock2 = 0;
	Load2 = 0;
	Data3 = 0;
	Clock3 = 0;
	Load3 = 0;
}

void shiftOut1(unsigned char val){
	unsigned int i;
	for(i=0; i<8; i++){
		Data1 = val & (1 <<(7-i));
		Clock1 = 1;
		Clock1 = 0;
	}
	Load1 = 1;
	Load1 = 0;
}

void shiftOut2(unsigned char val){
	unsigned int i;
	for(i=0; i<8; i++){
		Data2 = val & (1 <<(7-i));
		Clock2 = 1;
		Clock2 = 0;
	}
	Load2 = 1;
	Load2 = 0;
}

void shiftOut3(unsigned char val){
	unsigned int i;
	for(i=0; i<8; i++){
		Data3 = val & (1 <<(7-i));
		Clock3 = 1;
		Clock3 = 0;
	}
	Load3 = 1;
	Load3 = 0;
}

void displayNumber2(unsigned int number){
    switch (number) {
        case '0':
            shiftOut2(0xC0);
            break;
        case '1':
            shiftOut2(0xF9);
            break;
        case '2':
            shiftOut2(0xA4);
            break;
        case '3':
            shiftOut2(0xB0);
            break;
        case '4':
            shiftOut2(0x99);
            break;
        case '5':
            shiftOut2(0x92);
            break;
        case '6':
            shiftOut2(0x82);
            break;
        case '7':
            shiftOut2(0xF8);
            break;
        case '8':
            shiftOut2(0x80);
            break;
        case '9':
            shiftOut2(0x90);
            break;
        default:
            shiftOut2(0x00);
            break;
    }
}

void displayNumber1(unsigned int number){
    switch (number) {
        case '0':
            shiftOut1(0xC0);
            break;
        case '1':
            shiftOut1(0xF9);
            break;
        case '2':
            shiftOut1(0xA4);
            break;
        case '3':
            shiftOut1(0xB0);
            break;
        case '4':
            shiftOut1(0x99);
            break;
        case '5':
            shiftOut1(0x92);
            break;
        case '6':
            shiftOut1(0x82);
            break;
        case '7':
            shiftOut1(0xF8);
            break;
        case '8':
            shiftOut1(0x80);
            break;
        case '9':
            shiftOut1(0x90);
            break;
        default:
            shiftOut1(0x00);
            break;
    }
}

void displayCharacter(char character) {
    switch (character) {
        case 'A':
            shiftOut3(0x88);
            break;
        case 'B':
            shiftOut3(0x80);
            break;
        case 'C':
            shiftOut3(0xC6);
            break;
        case 'D':
            shiftOut3(0xC0);
            break;
        case 'E':
            shiftOut3(0x86);
            break;
        case 'F':
            shiftOut3(0x8E);
            break;
        case 'G':
            shiftOut3(0x82);
            break;
        case 'H':
            shiftOut3(0x89);
            break;
        case 'I':
            shiftOut3(0xF9);
            break;
        case 'J':
            shiftOut3(0xF0);
            break;
        default:
            shiftOut3(0x00);
            break;
    }
}

void main(void){
displayInit();
	while (1) {
        char number1[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        char number2[] = {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0'};
        char characters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
        unsigned int i;

        for (i = 0; i < 10; i++) {
            displayNumber1(number1[i]);
            displayNumber2(number2[i]);
            displayCharacter(characters[i]);
            msdelay(650);
        }
    }
}