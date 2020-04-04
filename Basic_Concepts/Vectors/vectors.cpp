#include <iostream> 
#include <vector> 

using namespace std; 
int main()
{
    vector <int> x ; 
    x.push_back(1);     
    x.push_back(2); 
    x.push_back(3); 
    x.push_back(4); 
    //vector<int>::iterator ptr; 
    for ( auto ptr = x.begin()    ; ptr!= x.end(); ptr++) 
        cout << *ptr << " ";
    cout <<endl; 
    return 0;  
}