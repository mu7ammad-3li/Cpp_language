#ifndef CALENDAR_H	// begin header guard
#define CALENDAR_H
#include<iostream> 
#include<iomanip> 
#include<string> 

using namespace std;
/*enum class month 
{
    January=1 , February,Mars=1,April,May,June,July,August,September,October,November,December
    
};
*/
enum class Week
{
    sat =0, sun,mon,tue,wed,thu,fri
};
class Calendar
{
public:
    Calendar();
    void askForDay(/*int &_day, int &_month, int &_year*/);
    string findDay();
    void printDay(/*int _day, int _month, int _year*/);

private:
    int day;
    int year;
    int month;
    
};


#endif 

