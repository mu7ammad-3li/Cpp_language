# UDACITY become c++ develoer nano degree



#   Part Two 
##      Module one Lesson 02 Introduction to the C++ Language
    
###  Read from file 
-       include fstream library 
-       intialize  an instance myFile ifstream class
-       call   member function open with "file location" as a parameter
-       if condition checks if the file is read correctly 
-       while loop reads the file line by line into a string until file stream ends 
        
```C++
        
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
                
```
###      Processing Strings
 we are using the `sstream` library 
 focusing on `istringstream` class 

```c++
#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;

int main() 
{
    string a("1 2 3");

    istringstream my_stream(a);

    int n;
    
    // Testing to see if the stream was successful and printing results.
    while (my_stream) {
        my_stream >> n;
        if (my_stream) {
            cout << "That stream was successful: " << n << "\n";
        }
        else {
            cout << "That stream was NOT successful!" << "\n";            
        }
    }
}
```

