#ifndef LCD_H
#define	LCD_H
#include <xc.h>
#define _XTAL_FREQ 4000000	/* Define freq */
#include <stdbool.h>

#define Command 1
    #define Text 0
#define lcdClear() (lcd_send(0x01, Command))
#define RS PORTDbits.RD4
#define EN PORTDbits.RD5
#define B4 PORTDbits.RD3
#define B5 PORTDbits.RD2
#define B6 PORTDbits.RD1
#define B7 PORTDbits.RD0

void lcd_Out(char data);
void lcd_send(char data, bool type);
void lcd_Initialization();
void lcd_setCursor_XY(char xCoordinate,char yCoordinate);
void lcd_printText_XY(const char *text, char xCoordinate,char yCoordinate);
void lcd_printNumber_XY(int number, char xCoordinate,char yCoordinate);
void lcd_createCustomChar(char location, char *pattern);
void lcd_printCustomChar_XY(char character, char xCoordinate,char yCoordinate);
void lcd_printCharacter_XY(char character, char xCoordinate,char yCoordinate);
void lcd_printCharacter(char character);

#endif	/* LCD_H */

