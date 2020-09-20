#include<iostream> 
#include <stdlib.h>     
#include <time.h>  
#include"conio.h"

using namespace std ;

bool gameOver; 
const int Width =40; 
const int Hight =20; 
int xCord ,yCord ,fruitX ,fruitY, Score; 
int tailX[100], tailY[100];
int nTail;

enum Direction { Stop =0, Left , Right, Up, Down }; 
Direction dir ; 

void Setup ()
{
    gameOver = false ; 
    dir = Stop; 
    xCord = Width/2; 
    yCord = Hight/2; 
    srand (time(NULL));
    fruitX = rand() % 37+1; 
    fruitY = rand() % 19+1; 
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
    switch (c)
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
        fruitX = rand() % 38+1; 
        fruitY = rand() % 18+1; 
        nTail++;
    }
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == xCord && tailY[i] == yCord)
        {
            gameOver = true;
            cout << "\nGame Over tail\n"<< endl;
        }
                            
    
    if (xCord <= 0 || xCord > Width-2 || yCord <=   0 ||yCord > Hight-2)
    {
        gameOver=true;
        cout << "\nGame Over wall\n"<< endl; 
    }


    
}


 
// Main Function 

int main ()
{
    
    Setup(); 
    Draw();
    while (!gameOver)
    { 
        
        
        Input(); 
        while (!_kbhit())
        {   
            Draw(); 
            Logic(); 
            fflush(stdout);
            usleep(200000);
        }
        
        
    }
    
return 0 ; 
}