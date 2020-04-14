#include<iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std; 

int main()
{
    /*
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
    */
        string b("1,2,3,");

        istringstream my_stream(b);

        char c;
        int n;
        if (my_stream){
        while (my_stream >> n >> c) {
            cout << "That stream was successful:" << n << " " << c << "\n";
        }
        cout << "The stream has ended." << "\n";
        }
        else 
            cout << "Stream failed "<< endl; 
}
