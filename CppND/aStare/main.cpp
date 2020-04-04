#include<iostream> 
#include <vector> 

using namespace std ; 

void printBoard(vector<vector<int>> aBoard); 

int main() 
{
    vector<vector<int>> board {{0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1, 0}}; 
    
    printBoard(board);
    return 0; 

}

void printBoard(vector<vector<int>> aBoard)
{
    for ( const auto &row : aBoard )
    {
            for ( const auto &s : row )
            cout <<  s << ' ';
            cout << endl;
    }        
}