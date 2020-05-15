#ifndef CALENDAR_H	// begin header guard
#define CALENDAR_H


enum class month 
{
    Mars=1,April,May,June,July,August,September,October,November,December,January , February
};

class Calendar
{
public:
    Calendar();
    void setFirstDay();
    void Print();

private:
    int year;
    month _month;
    int firstDay;
};



#endif
