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
*
* V1.3
* Expanding color printing macros now supports inputting strings or variables
*
* V1.4
* Expand the print and println macros. Previously, only one parameter could be output, but now you can input up to 10 parameters, achieving overloading
* 
* V1.5
* Implement printing for most basic types
* Improve annotations
*
* V1.6
* Add debug macros to print variable names and values
* Add the WARN_IF, ERR-IF, and ERR-EXIT.IF macros to test printing based on conditions
*
* V1.7
* Fix the issue of function conflicts when multiple files contain Print. h at the same time
* Add font macros to highlight, italic, underline, blink, and reverse text

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
 *
 * V1.3
 * 拓展颜色打印宏，现在可以支持输入字符串或变量了
 *
 * V1.4
 * 拓展print与println宏，以前只能输出1个参数，现在可以输入最多10个参数了，做到了重载
 *
 * V1.5
 * 实现对大部分基础类型的打印
 * 完善注释
 *
 * V1.6
 * 加入debug宏，可以打印变量名以及变量的值
 * 加入WARN_IF、ERR_IF、ERR_EXIT_IF宏，可以根据条件来测试打印
 *
 * V1.7
 * 修复多个文件同时包含Print.h时，函数冲突的问题
 * 加入字体宏，可以高亮、斜体、下划线、闪烁、反显文字
---
Usage
eg：

```c
#include "Print.h"

int main()
{
    char char_a = '0';
    unsigned char char_b = '1';

    short int sint_c = 2;
    int int_d = 3;
    unsigned int uint_e = 4;

    long long ll_f = 5l;
    unsigned long long ull_g = 6l;

    float float_h = 7.7;
    double double_i = 8.8f;

    const char* ccharx_j = "999";
    char* charx_k = "1234567890";

    int *intx_l = &int_d;
    long long *llx_m = &ll_f;
    unsigned long long *ullx_n = &ull_g;

    float *o = &float_h;
    double *p = &double_i;

    println(char_a, char_b, sint_c, int_d, uint_e, ll_f, ull_g, float_h, double_i);
    println(ccharx_j, charx_k, intx_l, llx_m, ullx_n, o, p);

    int num_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char ccl_str[10] = "ccl";

    println(GET_ARR_LEN(num_array));
    printlnArr(num_array, printArrTypeSpace);

    println(GET_ARR_LEN(ccl_str));
    printlnArr(ccl_str, printArrTypeName);

    println(GET_ARR_LEN("987654321"));

    TestColor("ccl is a boy");
    
    TestColor(char_a);

    print(RED(2));
    println(YELLOW(3.3));
    println(GREEN(3.3f));

    // Note that void types cannot be printed
    // 注意，不能打印void
    // print();

    println(HIGHTLIGHT("Look at me"));
    println(ITALIC("Look at me"));
    println(_("Look at me"));
    println(FLASGING("Look at me"));
    println(Reversedisplay("Look at me"));

    debug(char_a);

    WARN_IF(char_a == '0');
    ERR_IF(2 == 2);
    ERR_EXIT_IF(3 == 3);
    WARN_IF(char_a == 1);

    return 0;
}
```
    
Output：

```c
0
1
2
3
4
5
6
7.700000
8.800000
999
1234567890
000000000061FDC4
000000000061FDB8
000000000061FDB0
000000000061FDAC
000000000061FDA0
10
1 2 3 4 5 6 7 8 9 10
3
ccl_str[0] = c
ccl_str[1] = c
ccl_str[2] = l

9
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
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
23.300000
3.300000
Look at me
Look at me
Look at me
Look at me
Look at me
debug: char_a = 0
warning: char_a == '0'
error: 2 == 2
error: 3 == 3
```
    
![test.png](https://github.com/COSMICAL-CONTAINER/C_Program-Print.h/blob/main/pic/test.png)

You can see that we pass in different types of variables for the print macro to print, and ultimately all can output
你可以看到，我们为打印宏传递了不同类型的变量，最终所有变量都可以输出
