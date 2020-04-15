# UDACITY become c++ develoer nano degree



#   Part Two 
##      Module one Lesson 02 Introduction to the C++ Language
    
##  `Read from file `

-   Include fstream library 
-   Intialize  an instance myFile ifstream class
-   Call   member function open with "file location" as a parameter
-   If condition checks if the file is read correctly 
-   While loop reads the file line by line into a string until file stream ends 
        
```C++
        
ifstream myFile; 
myFile.open("Files/1.board");
f (myFile)
    {
       cout <<"File stream Created "<<endl; 
        string line; 
        while (getline(myFile,line))
        {
            cout <<line<<endl; 
        }
    }
                
```
##   `Processing Strings`

-    We are using the `sstream` library 
     Focusing on `istringstream` class 

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
- `Important note the previous was caused a logical error when We were Reading from a file `
    
    so we used 
```c++ 
while (my_stream>>n )
{
    // pushed into a vector 
}
```

#### `StringProcessing.cpp` 
-   intiated a file stream `boardFile`  
-   created a vector of vector of int to hold the board `boardVector`
-   while loop to read the file stream ino a string line by line 
-   created a temporary vector of int to read the board Rows values
`now starts the fun `
-   creat a `istringstream` class `Fstream` to read lines into 
-   ```c++
        while (Fstream >> n >> c)
    ```
    this loop will assure that as long as the stream is in this configuration the desired function inside will be applied 
    which is to push `int n` int the temporary vector 
-   And at the last push that temporary vector into our vector of vectors before  reading the next  line untill the stream is over resulting the following :
```
File Stream was created 
0 1 0 0 0 0 
0 1 0 0 0 0 
0 1 0 0 0 0 
0 1 0 0 0 0 
0 0 0 0 1 0 
0 1 1 0 0 1 
```