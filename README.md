# C_Program-Print.h
Include a header file and implement the print macro in C language, similar to the print function in Python

The project includes
A header file Print. h
A test file main. c

The print macro, using C11's _Generic (generic macro) to determine the type of input objects and call different printf print functions

Usage
eg：

```c
#include "Print.h"

int main()
{
    int num1 = 1;
    short int num2 = 2;
    char num3 = '3';
    float num4 = 4.0f;
    double num5 = 5.0;
    const char *str1 = "6";
    char str2[] = "7";
    
    print(num1);
    print(num2);
    print(num3);
    print(num4);
    print(num5);
    print(str1);
    print(str2);
    print("\n");

    println(num1);
    println(num2);
    println(num3);
    println(num4);
    println(num5);
    println(str1);
    println(str2);

    return 0;
}
```
    
Output：

```c
1234.0000005.00000067
1
2
3
4.000000
5.000000
6
7
```
    
You can see that we pass in different types of variables for the print macro to print, and ultimately all can output
