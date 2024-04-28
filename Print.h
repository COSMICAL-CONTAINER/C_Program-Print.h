/**
 * @file Print.h
 * @author Cosmical Containter
 * @brief Print anything you want!
 * @version 1.2
 * @date 2024-01-05
 * 
 * @copyright Copyright (c) 2024
 * 
 * @see
 * V1.0 
 * 完成基础功能，实现对基础类型char、short int、int、float、double、const char *、char *的打印
 * 
 * V1.1
 * 尝试不调用函数直接展开-失败
 * 
 * V1.2
 * 加入unsigned long long 的打印格式
 * 加入打印函数功能，可以自选打印格式
 * 加入不支持的格式错误处理
 * 加入颜色打印代码
 */

#ifndef __Print_H__
#define __Print_H__

#include <stdio.h>
#include <string.h>

#define print(obj) (_Generic((obj),\
    char:		        print_char,\
    short int:	        print_short,\
    int:		        print_int,\
    float:		        print_float,\
    double:		        print_double,\
    const char*:        print_cstr,\
	char *:		        print_str,\
    unsigned long long: print_ulonglong,\
    default:            print_error\
    )(obj))

#define println(obj) {print(obj); printf("\n");}

void print_char(char num)
{
    printf("%c", num);
}

void print_short(short int num)
{
    printf("%hd", num);
}

void print_int(int num)
{
    printf("%d", num);
}

void print_ulonglong(unsigned long long num)
{
    printf("%llu", num);
}

void print_float(float num)
{
    printf("%f", num);
}

void print_double(double num)
{
    printf("%lf", num);
}

void print_cstr(const char *str)
{
    printf("%s", str);
}

void print_str(char *str)
{
    printf("%s", str);
}

#define NONE(str) str      "\033[m"
#define RED(str)           "\033[0;32;31m"NONE(str)
#define LIGHT_RED(str)     "\033[1;31m"NONE(str)
#define GREEN(str)         "\033[0;32;32m"NONE(str)
#define LIGHT_GREEN(str)   "\033[1;32m"NONE(str)
#define BLUE(str)          "\033[0;32;34m"NONE(str)
#define LIGHT_BLUE(str)    "\033[1;34m"NONE(str)
#define DARY_GRAY(str)     "\033[1;30m"NONE(str)
#define CYAN(str)          "\033[0;36m"NONE(str)
#define LIGHT_CYAN(str)    "\033[1;36m"NONE(str)
#define PURPLE(str)        "\033[0;35m"NONE(str)
#define LIGHT_PURPLE(str)  "\033[1;35m"NONE(str)
#define YELLOW(str)        "\033[0;33m"NONE(str)
#define LIGHT_YELLOW(str)  "\033[1;33m"NONE(str)
#define LIGHT_GRAY(str)    "\033[0;37m"NONE(str)
#define WHITE(str)         "\033[1;37m"NONE(str)

#define TestColor(str)\
{\
    println(RED         (str));\
    println(LIGHT_RED   (str));\
    println(GREEN       (str));\
    println(LIGHT_GREEN (str));\
    println(BLUE        (str));\
    println(LIGHT_BLUE  (str));\
    println(CYAN        (str));\
    println(LIGHT_CYAN  (str));\
    println(PURPLE      (str));\
    println(LIGHT_PURPLE(str));\
    println(YELLOW      (str));\
    println(LIGHT_YELLOW(str));\
    println(DARY_GRAY   (str));\
    println(LIGHT_GRAY  (str));\
    println(WHITE       (str));\
}
#define TestColur TestColor

void print_error(void *data)
{
    println(RED( "print error!" ));
    println(RED( "don't have this type to print!" ));
}

#define printArrTypeSpace 0
#define printArrTypeln    1
#define printArrTypeName  2

#define GET_ARR_LEN(arrobj) \
	(_Generic((arrobj),\
    char *:		  strlen((const char *)arrobj),\
    default:      (sizeof(arrobj) / sizeof(arrobj[0]))\
    ))

#define printArr(ArrName, type) {     \
    for (int i = 0; i < GET_ARR_LEN(ArrName); i++)    \
    {                                       \
        if(type == printArrTypeName)        \
        {                                   \
            print(#ArrName);                \
            print("[");                     \
            print(i);                       \
            print("] = ");                  \
            println(ArrName[i]);            \
        }                                   \
        else                                \
        {                                   \
            print(ArrName[i]);              \
            if(type)    print("\n");        \
            else        print(" ");         \
        }                                   \
    }                                       \
}

#define printlnArr(ArrName, type) {printArr(ArrName, type); print("\n");}

// void print_char(char num);
// void print_short(short int num);
// void print_int(int num);
// void print_float(float num);
// void print_double(double num);
// void print_cstr(const char *str);
// void print_str(char *str);

#endif // !__Print_H__