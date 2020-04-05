#include<iostream>
#include <fstream>
#include <string>

using namespace std; 

int main()
{
    ifstream myFile; 
    myFile.open("Files/1.board");
    if (myFile)
    {
        cout <<"File stream Created "<<endl; 
        string line; 
        while (getline(myFile,line))
        {
            cout <<line<<endl; 
        }
        
    }
}