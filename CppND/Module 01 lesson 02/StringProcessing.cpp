#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

ifstream boardFile; //intialize file ftream board
vector<vector<int>> boardVector;

int main()
{
    boardFile.open("Files/1.board"); //read from 1.board
    if (boardFile)
        cout << "File Stream was created " << endl; //confirm read sucsess
    string Line;
    while (getline(boardFile, Line)) //read lines from the file dtream into Line 
    {

        vector<int> temp;

        istringstream Fstream(Line); //intialize a string stream
        int n;
        char c;
        while (Fstream >> n >> c)
        {

            cout << n << " ";
            temp.push_back(n); //push the values into temp vector
        }
        cout << endl;
        boardVector.push_back(temp); // push the vector into our vector of vectors
    }
    /* test sucsess 
    for (int i = 0; i < boardVector.size(); i++)
    {
        for (int j = 0; j < boardVector[i].size(); j++)
        {
            cout << boardVector[i][j] << " ";
        }
        cout << endl;
    }
    */
}