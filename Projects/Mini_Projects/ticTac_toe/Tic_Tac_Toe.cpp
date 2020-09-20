#include <iostream> 
#include<vector> 

using namespace std ; 

const int Width =13; 
const int Hight =7; 
int counter=0;
int userIn;
bool gameOver = false; 


enum class state {
    emptyCell=0, xCell, oCell
};
char cellReturn (state cell )
{
    switch (cell)
    {
    case state::emptyCell:
        return '-';
        break;
    case state::oCell: 
        return 'O'; 
        break;
    case state::xCell:
        return 'X';
        break;
    default:
        break;
    };
}
/*char cellReturn (state cell,char count )
{
    switch (cell)
    {
    case state::emptyCell:
        return count;
        break;
    case state::oCell: 
        return 'O'; 
        break;
    case state::xCell:
        return 'X';
        break;
    }
}*/

vector<state> cells(9);
 

 void setup()
 {

 }
 void draw()
 {
     system("clear");
     for (int i = 0; i < Hight; i++)

     {
         if (i == 0 || i == Hight - 1 || i % 2 == 0)
         {
             for (int i = 0; i < Width; i++)
             {
                 cout << "*";
             }
             cout << endl;
         }

         else
         {
             for (int j = 0; j < Width; j++)
             {
                 if (j == 0 || j == Width - 1 || j % 4 == 0)
                     cout << "*";

                 else
                 {
                     cout << " " << cellReturn(cells[counter]) << " ";
                     counter++;
                     j += 2;
                 }
             }
             cout << endl;
         }
     }
 }

int main ()
{
    while (!gameOver)
    {
        draw();
        //break;
        //input();
    }
    
    
}