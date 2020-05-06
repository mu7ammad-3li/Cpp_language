#ifndef CALENDAR_H	// begin header guard
#define CALENDAR_H


using namespace std;

class Calendar
{
public:
    Calendar();
    void setFirstDay();
    void Print();

private:
    int year;
    int month;
    int firstDay;
};

#endif
