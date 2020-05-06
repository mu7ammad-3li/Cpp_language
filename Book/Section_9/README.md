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
        date(int y ,int m, int d); 
        void add_day (int d); 
        void add_month(int m); 
        void add_year(int y); 
}
```
#### defining a member function 

```C++ 
date::date(int yy, int mm, int dd)
{
    :y{yy},m{mm},d{dd}; 
}
void add_day(int n)
{ 
    //...
}
/// constructors can be written this way 
date::date(iny yy,int mm, int dd)
{
    y=yy; 
    m=mm; 
    d=dd; 
}
```
#### refering to a current object 

```c++ 
date birthday; 
cout << birthday.month<<"\n"; 
```
#### Reporting Error 

```c++ 
class date
{
    public: 
        class invalid {}; 
        date(int yy , int mm, int dd); 
        //...
    private: 
        int y,d,m; 
        bool is_valid(); 
    
}
date::date(int yy , int mm , int dd)
{
    :y{yy},m{mm},d{dd}; 
    if (!is_valid())
        throw invalid{}; 
}
bool date::is_valid()
{
    if (m<1||m>12)
        return false 
    //...
}

void f (int x ,int y)
try
{
    date dxy{2004,x,y}; 
    cout<<dxy<<"\n"; 
    dxy.add_day(2); 
}
catch (date::invalid)
{
    cerr<<"invalid date"<<"\n"; 
}
```
### enumeration
an `enum` is a user-defined type spcifying its set of values (enumerations ) as a set of constants 

for examble :
```c++
enum class month 
{ 
    jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
}; 

```
The “body” of an enumeration is simply a list of its enumerators. The class in enum class means
that the enumerators are in the scope of the enumeration. That is, to refer to jan, we have to say
Month::jan.

You can give a specific representation value for an enumerator, as we did for jan here, or leave it to
the compiler to pick a suitable value. If you leave it to the compiler to pick, it’ll give each enumerator
the value of the previous enumerator plus one. Thus, our definition of Month gave the monthsconsecutive values starting with 1. We could equivalently have written
    If we don’t initialize the first enumerator, the count starts with 0. For example:
```c++
    enum cla ss Da y {
monda y, tuesda y, wednesda y, thursda y, frida y, sa turda y, sunda y
};
```
Here monday is represented as 0 and sunday is represented as 6. In practice, starting with 0 is often
a good choice.
We can use our Month like this:

```c++
Month m = Month::feb;
Month m2 = feb;// error: feb is not in scope
m = 7;// error: can’t assign an int to a Month
int n = m;// error: can’t assign a Month to an int
Month mm = Month(7);// convert int to Month (unchecked)
```
If you insist on using the Month(9999) notation, on your head be it! In many cases, C++ will not try
to stop a programmer from doing something potentially silly when the programmer explicitly insists;
after all, the programmer might actually know better. Note that you cannot use the Month{9999}
notation because that would allow only values that could be used in an initialization of a Month, and
ints cannot.


Unfortunately, we cannot define a constructor for an enumeration to check initializer values, but it
is trivial to write a simple checking function:

```c++
Month int_to_month(int x)
{
if (x<int(Month::ja n) || int(Month::dec)<x) cerr<<"bad month\n";
return Month(x);
}
```

We use the int(Month::jan) notation to get the int representation of Month::jan. Given that, we can
write

```c++ 
void f(int m)
{
Month mm = int_to_month(m);
// . . .
}
```
#### “Plain” enumerations

In addition to the enum classes, also known as scoped enumerations, there are “plain” enumerations
that differ from scoped enumerations by implicitly “exporting” their enumerators to the scope of the
enumeration and allowing implicit conversions to int. For example:

```c++ 
enum Month {    // note : no “class”

ja n=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
Month m = feb;  // OK: feb in scope
Month m2 = Month::feb;  // also OK
m = 7;      // error: can’t assign an int to a Month
int n = m;      // OK: we can assign a Month to an int
Month mm = Month(7);    // convert int to Month (unchecked)
```

Obviously, “plain” enums are less strict than enum classes. Their enumerators can “pollute” the
scope in which their enumerator is defined. That can be a convenience, but it occasionally leads to
surprises. For example, if you try to use this Month together with the iostream formatting
mechanisms , you will find that dec for December clashes with dec for decimal.

Similarly, having an enumeration value convert to int can be a convenience (it saves us from being
explicit when we want a conversion to int), but occasionally it leads to surprises. For example:
```c++
Click here to view code image
void my_code(Month m)
{   
If (m==17) do_something();  // no error 
If (m==monday) do_something_else();    //no error either 
}
```
If Month is an enum class, neither condition will compile. If monday is an enumerator of a “plain”
enum, rather than an enum class, the comparison of a month to Monday would succeed, most likely
with undesirable results.
Prefer the simpler and safer enum classes to “plain” enums, but expect to find “plain” enums in
older code: enum classes are new in C++11.

### OPERATOR OVERLOADING 

We use operator overloading to provide a coventional notation for our designed type 
```c++
enum class month 
{
    jan = 1 ,feb,mar,...,dec
}; 
month operator++(month&m)
{
    m=(m==dec)?jan : month (int(m)+1); // if m = dec m= jan else m = m+1 
    return m ; 
}
month m= feb ; 
++m ; //m becomes mar






