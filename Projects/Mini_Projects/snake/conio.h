#ifndef CONIO_H
#define CONIO_H
#include <termios.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace std ;

void initTermios(int echo) ;
void resetTermios(void) ;

 
/* Read 1 character - echo defines echo mode */
char getch_(int echo) ;
 
/* 
Read 1 character without echo 
getch() function definition.
*/
char getch(void) ;
/* 
Read 1 character with echo 
getche() function definition.
*/
char getche(void) ;

int _kbhit();

#endif
