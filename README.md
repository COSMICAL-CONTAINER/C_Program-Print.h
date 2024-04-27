# C_Program-Print.h
Include a header file and implement the print macro in C language, similar to the print function in Python

The project includes
## file:
A header file Print. h
A test file main. c

## macro:
The print macro, using C11's _Generic (generic macro) to determine the type of input objects and call different printf print functions

The Color macro:
RED         
LIGHT_RED   
GREEN       
LIGHT_GREEN 
BLUE        
LIGHT_BLUE  
CYAN        
LIGHT_CYAN  
PURPLE      
LIGHT_PURPLE
YELLOW      
LIGHT_YELLOW
DARY_GRAY   
LIGHT_GRAY  
WHITE

These macros can directly affect strings, making them appear colored when printed on the screen
For example, if we use print(RED ("test")), we will output red text on the screen
Using print(LIGHT RED ("test"))will output bright red text on the screen

Get_ARR_LEN macro, capable of obtaining the length of an array

The printArr macro allows for direct printing of arrays, with a total of three printing methods to choose from

* V1.0
* Complete basic functions and print basic types char, short int, int, float, double, const char *, char *
*
* V1.1
* Fix bugs
* 
* V1.2
* Add an unsigned long long printing format
* Add the function of printing arrays, which allows users to choose the printing format for every two elements in the array
* Add unsupported format error handling
* Add color printing code
---
# C语言 Print.h
包括一个头文件并用C语言实现打印宏，类似于Python中的打印函数

该项目包括
## 文件：
头文件       Print.h
一个测试文件  main.c

## 宏：
print宏，使用C11的_Generic（泛型宏）来确定输入对象的类型并调用不同的printf打印函数进行打印

各种颜色宏:
RED         
LIGHT_RED   
GREEN       
LIGHT_GREEN 
BLUE        
LIGHT_BLUE  
CYAN        
LIGHT_CYAN  
PURPLE      
LIGHT_PURPLE
YELLOW      
LIGHT_YELLOW
DARY_GRAY   
LIGHT_GRAY  
WHITE
这些颜色宏能直接作用于字符串，使得字符串在屏幕上打印出是有颜色的
比如我们使用print(RED("test"))就会在屏幕上输出红色的文字
使用print(LIGHT_RED("test"))就会在屏幕上输出亮红色的文字

GET_ARR_LEN宏，能够获取数组的长度

printArr宏，能够直接打印数组，一共有三种打印方式可供选择

 * V1.0 
 * 完成基础功能，实现对基础类型char、short int、int、float、double、const char *、char *的打印
 * 
 * V1.1
 * 修复bug
 * 
 * V1.2
 * 加入unsigned long long 的打印格式
 * 加入打印数组功能，可以自选数组中每两个元素的打印格式
 * 加入不支持的格式错误处理
 * 加入颜色打印代码
---
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

    int num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char ccl[10] = "ccl";

    println(GET_ARR_LEN(num));
    printlnArr(num, printArrTypeSpace);

    println(GET_ARR_LEN(ccl));
    printlnArr(ccl, printArrTypeSpace);

    println(GET_ARR_LEN("987654321"));

    int *p = 0;
    print(p);

    TestColor("ccl is a boy");

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
10
1 2 3 4 5 6 7 8 9 10 
3
c c l 
9
print error!
don't have this type to print!
ccl is a boy
ccl is a boy
ccl is a boy
ccl is a boy
ccl is a boy
ccl is a boy
ccl is a boy
ccl is a boy
ccl is a boy
ccl is a boy
ccl is a boy
ccl is a boy
ccl is a boy
ccl is a boy
ccl is a boy
```
    
![test.png](https://github.com/COSMICAL-CONTAINER/C_Program-Print.h/blob/main/pic/test.png)

You can see that we pass in different types of variables for the print macro to print, and ultimately all can output
你可以看到，我们为打印宏传递了不同类型的变量，最终所有变量都可以输出
