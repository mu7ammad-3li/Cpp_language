#include<iostream> 
#include<iomanip> 
#include<string> 
#include "Calendar.h"

using namespace std ; 

Calendar::Calendar() {};

void Calendar::askForDay(/*int &_day, int &_month, int &_year*/)
{
    cout <<"Enter your day : ";
    int day,month,year;
    cin >> day;
    Calendar::day=day; 
    cout <<"Enter your Month : ";
    cin>> month;
    Calendar::month=month; 
    cout <<"Enter your Year : ";
    cin>>year; 
    Calendar::year=year; 
}


string  Calendar::findDay()
{ 
    int d = Calendar::day; 
    int m = Calendar::month; 
    int y = Calendar::year; 
    int n=0 ; 
    n= (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400+2)%7; 
    switch (Week(n))
    {
        case Week::sat:
        return "saturday"; 
        case Week::sun:
        return "sunday";
        case Week::mon:
        return "monday"; 
        case Week::tue:
        return "tuseday"; 
        case Week::wed:
        return "wednesday"; 
        case Week::thu:
        return "thursday"; 
        case Week::fri:
        return "friday"; 
    }
}
void Calendar::printDay(/*int _day, int _month, int _year*/)
{
    cout << "your day is : "; 
    cout << Calendar::day<<setw(4)<<Calendar::month<<setw(6)<<Calendar::year<<endl;
    cout <<Calendar::findDay()<<endl;
}   