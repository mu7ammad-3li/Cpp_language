#include<iostream> 
#include<iomanip> 
#include<string> 
#include "Calendar.h"


Calendar::Calendar() : month{5}, year{2020} {};

void Calendar::setFirstDay(){

	int day=1;
	int y = year - (14-month)/12;
	int m = month +12 * ((14-month) / 12) -2;
	firstDay= (day + y + y / 4 - y / 100 + y / 400 + (31 * m / 12)) % 7;
};

void Calendar::Print()
{
    int daysInMonth = 0;
    int firstDayOfMonth = 0;
    int daysInWeekCounter = 0;
    int dateCounter = 1;
    switch (month)
    {
    case 1:
        cout << setw(20) << "January " << year;
        daysInMonth = 31;
    case 2:
        cout << setw(20) << "February " << year;
        //cange into a bool function
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    case 3:
        cout << setw(20) << "Mars " << year;
        daysInMonth = 31;
    case 4:
        cout << setw(20) << "April " << year;
        daysInMonth = 30;
    case 5:
        cout << setw(20) << "May " << year;
        daysInMonth = 31;
    case 6:
        cout << setw(20) << "June " << year;
        daysInMonth = 30;
    case 7:
        cout << setw(20) << "July " << year;
        daysInMonth = 31;
    case 8:
        cout << setw(20) << "August " << year;
        daysInMonth = 31;
    case 9:
        cout << setw(20) << "September " << year;
        daysInMonth = 30;
    case 10:
        cout << setw(20) << "October " << year;
        daysInMonth = 31;
    case 11:
        cout << setw(20) << "November " << year;
        daysInMonth = 30;
    case 12:
        cout << setw(20) << "December" << year;
        daysInMonth = 31;
    }

//Display the days at the top of each month

    cout << "\nSun   Mon   Tue   Wed   Thu   Fri   Sat";
    cout << "\n\n"
         << setw(2);
//Determine where the first day begins
    for (firstDayOfMonth; firstDayOfMonth < firstDay; ++firstDayOfMonth)
    {
        cout << setw(15);
    }
    int tempFirst = firstDay;
    dateCounter = 1;
    daysInWeekCounter = tempFirst;
//This loop represents the date display and will continue to run until
//the number of days in that month have been reached
    
	for (dateCounter; dateCounter <= daysInMonth; ++dateCounter)
	{
		cout<<dateCounter<<setw(6);
		++daysInWeekCounter;
		if (daysInWeekCounter > 6)
		{
			cout<<"\n\n"<<setw(2);
			daysInWeekCounter = 0;
		}
	}
    cout << " \n" ;

	tempFirst = daysInWeekCounter + 1;
}