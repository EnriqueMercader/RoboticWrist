#include "lcd.h"

void lcd_Out(char data){
        if (data & 1){
            B4 = 1;
        }
        else{
            B4 = 0;
        }
        if (data & 2){
            B5 = 1;
        }
        else{
            B5 = 0;
        }
        if (data & 4){
            B6 = 1;
        }
        else{
            B6 = 0;
        }
        if (data & 8){
            B7 = 1;
        }
        else{
            B7 = 0;;
        }
    }
void lcd_send(char data, bool type){
    
    lcd_Out((((data) >> 4) & 0x0F));
    if (type == Command){
        RS = 0;
    }
    else{
        RS = 1;
    }
    EN = 1;
        EN = 0;
    __delay_ms(1);
    lcd_Out(((data) & 0x0F));            //Send lower nibble of data to PORT
    EN = 1;
        NOP();
        EN = 0;
        __delay_ms(3);
    
    }   
void lcd_Initialization(){   
        __delay_ms(15);     //15ms,16x2 lcd Power on delay
        lcd_send(0x02, Command);  //Nibble (4-bit) mode                     
        lcd_send(0x28, Command); //use 2 line and initialize 5*8 matrix in (4-bit mode)
        lcd_send(0x0c, Command);  //display on cursor off
        lcd_send(0x06, Command);   //increment cursor (shift cursor to right)
        lcd_send(0x01, Command);   //clear display screen
    }
void lcd_setCursor_XY(char xCoordinate,char yCoordinate){
    lcd_send(((64+(64*yCoordinate)) | ((xCoordinate-1) & 0x0f)), Command);
    }
void lcd_printText_XY(const char *text, char xCoordinate,char yCoordinate){
        lcd_setCursor_XY(xCoordinate, yCoordinate);  
        while((*text)!=0){		
            lcd_send(*text, Text);
            text++;	
        }
    }
void lcd_printNumber_XY(int number, char xCoordinate,char yCoordinate){
    //Variables
    char i = 0;
    char string[4];
    char temp;
    char j;
    char k;

    //Code
    /*Number Splitting and storing into a string as ASCII characters.*/
    while (number != 0) {                               //Divides a number into its characters.
        string[i] = (number % 10) + '0';    //Stores each character in a string.
        number /= 10;
        i++;                                            //Shifts the string position for the next character.
    }
    if (i == 0) {                                       //If the number is a 0.
        string[i] = '0';                    //Writes the ASCII number 0 to the string.
        i++;                                            //Shifts the string position for the null terminator.
    }

    /*Array characters position reversing*/
    for (j = 0, k = i-1; j < k; j++, k--) {             //Reverses the string's characters. EG. [A][B][C]
        temp = string[j];                   //       temp = A
        string[j] = string[k];  //  --->[C][B][C]
        string[k] = temp;                   //      [C][B][A]<---
    }
    string[i] = '\0';                       //Appends the null terminator at the end.
    lcd_printText_XY(string,xCoordinate,yCoordinate);
} void lcd_createCustomChar(char location, char *pattern) {
    unsigned char i;
     lcd_send((0x40 + (location*8)),Command);    /* Command 0x40 and onwards forces the device to point CGRAM address */
     for(i=0;i<8;i++)    /* Write 8 byte for generation of 1 character */
        lcd_send(pattern[i], Text);       
}
void lcd_printCustomChar_XY(char character, char xCoordinate,char yCoordinate){
    lcd_setCursor_XY(xCoordinate,yCoordinate);
    lcd_send(character, Text);
}
void lcd_printCharacter_XY(char character, char xCoordinate,char yCoordinate){
    lcd_setCursor_XY(xCoordinate,yCoordinate);
    lcd_send(character, Text);
}

void lcd_printCharacter(char character){
    lcd_send(character, Text);
}