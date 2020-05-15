#include "DateClass.h"

using namespace std; 

class Year 
{
     const int max = 2050; 
     const int min =1900; 
    public: 
        class invalid {}; 
        Year( int x):_Year{x}{if (x<min ||x >max )throw invalid {};};
         
    private: 
        int _Year; 
}; 
enum class Month
{ 
    jan=1 , feb, mar, apr, may, jun, jul, aug , sept, oct , nov ,dec
};


class Date { 
    public:
        Date(int year, int month , int day);
    private: 
        int _Year; 
        int _Month; 
        int _Day; 

}; 
