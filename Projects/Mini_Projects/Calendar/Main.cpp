#include<iostream> 
#include<iomanip> 
#include<string> 
#include "Calendar.h"
using namespace std; 

int main ()
{ 
    Calendar c;
    system("clear");
    c.setFirstDay(); 
    c.Print();
    cin.get(); 
    return 0;
}