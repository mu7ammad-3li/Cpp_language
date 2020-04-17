#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

vector<int> ParseLine(string Line);
ifstream boardFile;
vector<vector<int>> boardVector;

int main()
{
    //Read file into board file
    boardFile.open("Files/1.board");
    if (boardFile)
        cout << "File Stream is sucsessful" << endl;
    else
        cerr << "File stream failed " << endl;
    string Line;
    while (getline(boardFile, Line))
    {
        vector<int> temp;
        temp = ParseLine(Line);
        boardVector.push_back(temp);
    }
    /* test result 
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

vector<int> ParseLine(string Line)
{
    vector<int> pTemp;

    istringstream Fstream(Line); //intialize a string stream
    int n;
    char c;
    while (Fstream >> n >> c)
    {

        
        pTemp.push_back(n); //push the values into temp vector
    }
    return pTemp; 
}