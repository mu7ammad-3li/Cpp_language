# PROGRAMMING : PRINCIPLES AND PRACTICE USING C++ 

## CHAPETER 9 : TECHNICALITIES (CLASSES, ETC.)

### USER DEFINED TYPES (UDTs)

User defined types helps us in two ways: 

- Representation: A type “knows” how to represent the data needed in an object.
- Operations: A type “knows” what operations can be applied to objects.

### CLASS AN MEMBERS 

A class is a user defined type. class elements are called members. A clsss can contain zero or more class members. 

```c++
class grammer
{
private:
    /* data */
public:
int m ; 
};
```
`m` is a class member 
class members are accessible through the following notation 
```c++
class.member ; 
```
### INTERFACE AND IMPLEMENTATION

A class is usually `interface` which is the part accessible directly by the user `public`

`implementaion` which is the part only accessible through an interface `private`

class member are private by default 

```c++ 
class X 
{
    int mf(int m); 
}; 
//Means 
class X
{
    private: 
        int mf(int m); 
}; 
```
A user can not refere directly to a private member, Instead it can happen through a function in public interface    

### EVELVING A CASE 
####    STRUCT AND FUNCTIONS 

```c++
struct date 
{
    int year ; 
    int month ; 
    int day ; 
}

date today; 
```

This ok but tedious and error-prone. For example: 
```c++ 
today.year=-3;
today.month=13; 
today.day=50; 
```
We could write some functions to intialize and check the validity of the date 
but do we need all this hussle for such a type ?

This can be fixed by making the tybe members inaccessible to user exept eith an interface to check date validity 
```C++ 
class date
{
    private: 
        int y,m,d; 
    public: 
        Date(int y ,int m, int d); 
        void add_day (int d); 
        void add_month(int m); 
        void add_year(int y); 
}
