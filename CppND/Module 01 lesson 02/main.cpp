#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

enum class state{kEmpty,kObstacle};

vector<state> ParseLine(string Line);
vector<vector<state>> ReadBoardFile(string path);
void PrintBoard(const vector<vector<state>> board);

int main()
{
  auto board = ReadBoardFile("1.board");
  PrintBoard(board);
}

string CellString(state cell)
{
    switch (cell)
    {
    case state::kObstacle:
        return "🚧   ";
    default:
        return "🚦   ";
    }
}
vector<state> ParseLine(string Line)
{
    vector<state> Row;

    istringstream Fstream(Line); //intialize a string stream
    int n;
    char c;
    while (Fstream >> n >> c)
    {
        if (n==0)
            Row.push_back(state::kEmpty);
        else
            Row.push_back(state::kObstacle);
    }
    return Row; 
}

vector<vector<state>> ReadBoardFile(string path)
{
    ifstream boardFile;
    vector<vector<state>> boardVector;
    boardFile.open("Files/1.board");

    if (boardFile)
    {
        cout << "File Stream is sucsessful" << endl;
        string Line;
        while (getline(boardFile, Line))
        {
            vector<state> Row;
            Row = ParseLine(Line);
            boardVector.push_back(Row);
        }
        return boardVector;
    }
    else
    {
        cerr << "File stream failed " << endl;
        return boardVector;
    }
}
void PrintBoard(const vector<vector<state>> board) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[i].size(); j++) {
      cout << CellString(board[i][j]);
    }
    cout << "\n";
  }
}