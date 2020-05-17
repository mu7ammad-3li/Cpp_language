#include<iostream> 
//#include<ncurses.h>
#include <termios.h>
#include <stdio.h>
#include <sys/ioctl.h>


using namespace std ;

bool gameOver; 
const int Width =40; 
const int Hight =20; 
int xCord ,yCord ,fruitX ,fruitY, Score; 
int tailX[100], tailY[100];
int nTail;
static struct termios _old ;
static struct termios _new;
/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &_old); //grab old terminal i/o settings
  _new = _old; //make new settings same as old settings
  _new.c_lflag &= ~ICANON; //disable buffered i/o
  _new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
  tcsetattr(0, TCSANOW, &_new); //apply terminal io settings
}
 
/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &_old);
}
 
/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
 
/* 
Read 1 character without echo 
getch() function definition.
*/
char getch(void) 
{
  return getch_(0);
}
 
/* 
Read 1 character with echo 
getche() function definition.
*/
char getche(void) 
{
  return getch_(1);
}



enum Direction { Stop =0, Left , Right, Up, Down }; 
Direction dir ; 

void Setup ()
{
    gameOver = false ; 
    dir = Stop; 
    xCord = Width/2; 
    yCord = Hight/2; 
    fruitX = rand() % Width; 
    fruitY = rand() % Hight; 
    Score = 0;
}
void Draw ()
{ 
    system("clear"); 

    cout << "Score : "<<Score << endl; 
    for (int i =0 ; i <Hight; i++ )

    {
        if (i==0||i==Hight-1)
        {
             for (int i=0; i<Width; i++)
            {
                cout <<"*"; 
            }  
            cout <<endl;     
        }
        else
        {
            for (int j = 0; j < Width; j++)
            {
                if (j == 0 || j == Width - 1)
                    cout << "*";
                else if (i == yCord && j == xCord)
                    cout << "O";
                else if (i == fruitY && j == fruitX)
                {
                    cout << "🍏";
                    j++;
                }
                else
                {
                    bool print = false;
                    for (int k = 0; k < nTail; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print)
                        cout << " ";
                }
            }
            cout << endl;
        }
    }
}
void Input()
{

        char c = getch();
        
        switch (getch())
        {
        case 'w':
            dir = Up;
            
            break;
        case 's':
            dir = Down;
            
            break;
        case 'd':
            dir = Right;
            
            break;
        case 'a':
            dir = Left;
            
            break;
        case 'q':
            gameOver = true;
            cout << "\nGame Terminated\n"
                 << endl;
            break;

        }

}
void Logic ()
{   
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = xCord;
    tailY[0] = yCord;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case Left:
        xCord--;
        break;
    case Right:
        xCord++;
        break;
    case Up:
        yCord--;
        break;
    case Down:
        yCord++;
        break;
    }
    if (xCord==fruitX && yCord== fruitY)
    {
        Score +=10; 
        fruitX = rand() % 40; 
        fruitY = rand() % 20;
        nTail++;
    }
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == xCord && tailY[i] == yCord)
        {
            gameOver = true;
            cout << "\nGame Over\n"<< endl;
        }
                            
    
    if (xCord <= 0 || xCord > Width-2 || yCord <=   0 ||yCord > Hight-2)
    {
        gameOver=true;
        cout << "\nGame Over\n"<< endl; 
    }


    
}


 
// Main Function 

int main ()
{
    Setup(); 
    while (!gameOver)
    { 
        
        Draw(); 
        Input(); 
        Logic(); 
    }
    
return 0 ; 
}