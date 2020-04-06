#include<iostream> 
#include <vector> 
#include <string>
#include <fstream>

using namespace std ; 

void printBoard(string fPath ); 

int main() 
{
    printBoard("Files/1.board");
    return 0; 
}

void printBoard(string fPath )
{
    ifstream board_file;
    board_file.open(fPath);

    if (board_file)
    {
        cout <<"File stream Created "<<endl; 
        string line; 
        while (getline(board_file,line))
        {
            cout <<line<<endl; 
        }
        
    }     
}