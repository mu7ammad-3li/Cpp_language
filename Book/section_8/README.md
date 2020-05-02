# PROGRAMMING : PRINCIPLES AND PRACTICE USING C++ 

## CHAPETER 8 : TECHNICALITIES (FUNCTION)

### DECLARATION 
- Extern  keyword states that the declaration is not a definition . 
    Its rarly ueful  and not recommended 
    We can see it in codes containing too much global variables. 
- The c++ definition requires declarition first except in case of class members. 
    "declarition before use simplifies reading code for both human and compilers.

#### KIND OF DECLARATIONS 
-  Variables 
-  Constants 
-  Functions 
-  Namespaces 
-  Types 
-  Templates 

##### VARIABLES 

variables must be intialized before use _this is no exception _ 
when ever we dont supply our declaration with intial value a mechanism called ` Default constructor ` guarentee default intialization except for built in variables .
a global variable is intialized by default with 0, but we should minimize our use of them 
local and class member are unintialized unless we provid one or use default constructor. 

### HEADER FILES 
### SCOPE
### FUNCTION CALL AND RETURN

#### Pass by value 
A copy of the variable is passed to the function, So the value of the variable is not changed 

#### Pass by const reference 
If the variable is large for example an image, Passing by const refernce is more effecient 
copying the whole variable is costy, even though we should not be obssesed with cost 

``` c++ 
int x ; 
vector <int> v(x);
vector <int> k(100000); 
int z = funct(k);   
int y =funct(v); 
```
its not effecient to pass a large variable or variable with no defined size ; 
```c++ 
void print (const vector <int>&v)
```
The & part means referance,
 The const part is to stop the function from changing the variable by accedent. it is the same as call by value except instead of operating on a copy, we refere back to the argument itself. 

 #### pass by referance 

 inn this method we pass the referance of the variable with the availability of modifying the variable itself. 

 ```c++
 void init (vector <int> &x ){
     for (int =0 ; int <x.size(); i++)
        v[i]=i; 
 }
 ```
###### `What is a referance 

A referance is a construct that allows you to declare a new name for an object for examble : 
```c++ 
int i =10; 
int&r = i; 
r= 9;   // i now =9; 
```
r is a referance for i.

let 
```c++
vector <vector><int> x; 
int x = x[i,j]; 
int& y =x [i,j]; 
```
x is a copy of the vector element value, while y is a referance to the vector element itself meaning that the vector element can be read as well as get modified by the user. 

examble : 
```c++
void swap (int& d1 , int& d2){
    int temp = d1 ;
    d1=d2; 
    d2= temp;
}
```
note : standered library contains a buit-in swap() function 

in conclusion 

1. Use pass-by-value to pass very small objects.
2. Use pass-by-const-reference to pass large objects that you don’t need to modify.
3. Return a result rather than modifying an object through a reference argument.
4. Use pass-by-reference only when you have to.

Why do we ever use non-const-reference arguments? Occasionally, they are essential

- For manipulating containers (e.g., vector) and other large objects
- For functions that change several objects (we can have only one return value)

It is usually best to avoid functions that modify several objects. In theory, there are always
alternatives, such as returning a class object holding several values.
#### order of elevation 

#### namespaces 
We use blocks to organize code within a function (§8.4). We use classes to organize functions, data,
and types into a type  A function and a class both do two things for us:
- They allow us to define a number of “entities” without worrying that their names clash with
other names in our program.
- They give us a name to refer to what we have defined.

`Namespace` is something to organize classes, functions, data, and types into an identifiable
and named part of a program without defining a type.

##### `using` declarations and `using` directives

he facilities of the C++ standard library are defined in namespace std and can be used like this

```c++ 
std::cout <<"hello world "; 
std::cin>>x; 
```
we can use to allow us to refer the standerd librarry element `string` or `cout` for examble.

```c++
using std::string ; // string anywhere in the program means std::string 
using std::cout ; //// cout anywhere in the program means std::cout 
```
we can have the next line to make all names from std library accessible  
```c++ 
using namespace std ; 
```