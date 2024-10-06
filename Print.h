/**
 * @file Print.h
 * @author Cosmical Containter
 * @emile 1727585014@qq.com 
 * @github https://github.com/COSMICAL-CONTAINER
 * @brief Print anything you want!
 * @version 1.9
 * @date 2024-10-05
 * 
 * @copyright Copyright (c) 2024
 * 
 * @see
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
 * 
 * V1.8
 * 修复字体宏高亮、斜体、下划线、闪烁、反显文字打印变量时报错
 * 重写PrintMacroArgCount宏，现在可以获取没有参数的情况了，实现print()、println(),不传递参数默认打印空白或换行
 * 
 * V1.9
 * 增加endl宏用于换行处理
 */

#ifndef __Print_H__
#define __Print_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINTMAXSTRLEN 1000

// 颜色宏代码
// #define NONE(str)          str"\033[m"
// #define RED(str)           "\033[0;32;31m"NONE(str)
// #define LIGHT_RED(str)     "\033[1;31m"NONE(str)
// #define GREEN(str)         "\033[0;32;32m"NONE(str)
// #define LIGHT_GREEN(str)   "\033[1;32m"NONE(str)
// #define BLUE(str)          "\033[0;32;34m"NONE(str)
// #define LIGHT_BLUE(str)    "\033[1;34m"NONE(str)
// #define DARY_GRAY(str)     "\033[1;30m"NONE(str)
// #define CYAN(str)          "\033[0;36m"NONE(str)
// #define LIGHT_CYAN(str)    "\033[1;36m"NONE(str)
// #define PURPLE(str)        "\033[0;35m"NONE(str)
// #define LIGHT_PURPLE(str)  "\033[1;35m"NONE(str)
// #define YELLOW(str)        "\033[0;33m"NONE(str)
// #define LIGHT_YELLOW(str)  "\033[1;33m"NONE(str)
// #define LIGHT_GRAY(str)    "\033[0;37m"NONE(str)
// #define WHITE(str)         "\033[1;37m"NONE(str)

// // 原始字体宏
// #define NONE(str)          str"\033[m"
// // 高亮文字
// #define HIGHTLIGHT(str)    "\033[1m"NONE(str)
// // 斜体文字
// #define ITALIC(str)        "\033[3m"NONE(str)
// // 下划线文字
// #define _(str)             "\033[4m"NONE(str)
// // 闪烁文字
// #define FLASGING(str)      "\033[5m"NONE(str)
// // 反显文字 - 交换前景色和背景色
// #define Reversedisplay(str)      "\033[7m"NONE(str)

// 为了能够实现兼容字符串和变量的颜色打印，只能这样操作
// RED(a) 与 RED("1") 兼容
#define TOSTR(obj) (_Generic((obj),\
    char:		        char2str,\
    short int:	        short2str,\
    int:		        int2str,\
    float:		        float2str,\
    double:		        double2str,\
    const char*:        str2str,\
	char *:		        str2str,\
    unsigned long long: ulonglong2str,\
    default:            print_void_or_error\
    )(obj))

#define RED(obj)           (str_comb(str_comb("\033[0;32;31m",TOSTR(obj)),"\033[m"))
#define LIGHT_RED(obj)     (str_comb(str_comb("\033[1;31m"   ,TOSTR(obj)),"\033[m"))
#define GREEN(obj)         (str_comb(str_comb("\033[0;32;32m",TOSTR(obj)),"\033[m"))
#define LIGHT_GREEN(obj)   (str_comb(str_comb("\033[1;32m"   ,TOSTR(obj)),"\033[m"))
#define BLUE(obj)          (str_comb(str_comb("\033[0;32;34m",TOSTR(obj)),"\033[m"))
#define LIGHT_BLUE(obj)    (str_comb(str_comb("\033[1;34m"   ,TOSTR(obj)),"\033[m"))
#define DARY_GRAY(obj)     (str_comb(str_comb("\033[1;30m"   ,TOSTR(obj)),"\033[m"))
#define CYAN(obj)          (str_comb(str_comb("\033[0;36m"   ,TOSTR(obj)),"\033[m"))
#define LIGHT_CYAN(obj)    (str_comb(str_comb("\033[1;36m"   ,TOSTR(obj)),"\033[m"))
#define PURPLE(obj)        (str_comb(str_comb("\033[0;35m"   ,TOSTR(obj)),"\033[m"))
#define LIGHT_PURPLE(obj)  (str_comb(str_comb("\033[1;35m"   ,TOSTR(obj)),"\033[m"))
#define YELLOW(obj)        (str_comb(str_comb("\033[0;33m"   ,TOSTR(obj)),"\033[m"))
#define LIGHT_YELLOW(obj)  (str_comb(str_comb("\033[1;33m"   ,TOSTR(obj)),"\033[m"))
#define LIGHT_GRAY(obj)    (str_comb(str_comb("\033[0;37m"   ,TOSTR(obj)),"\033[m"))
#define WHITE(obj)         (str_comb(str_comb("\033[1;37m"   ,TOSTR(obj)),"\033[m"))
#define HIGHTLIGHT(str)    (str_comb(str_comb("\033[1m"      ,TOSTR(str)),"\033[m"))
// 斜体文字
#define ITALIC(str)              (str_comb(str_comb("\033[3m",TOSTR(str)),"\033[m"))
// 下划线文字
#define _(str)                   (str_comb(str_comb("\033[4m",TOSTR(str)),"\033[m"))
// 闪烁文字
#define FLASGING(str)            (str_comb(str_comb("\033[5m",TOSTR(str)),"\033[m"))
// 反显文字 - 交换前景色和背景色
#define Reversedisplay(str)      (str_comb(str_comb("\033[7m",TOSTR(str)),"\033[m"))

// 这是字符串合成函数
static inline const char* str_comb(const char *str1, const char *str2)
{
    static char str[PRINTMAXSTRLEN];
    strcpy(str, str1);
    strcat(str, str2);
    return str;
}

// 下面是处理各种类型转字符串的函数
static inline const char* char2str(char ch)
{
    static char str[2];
    str[0] = ch;
    str[1] = '\0';
    return str;
}

static inline const char* short2str(short num)
{
    // short：2字节 -32,768 到 32,767
    static char str[7];
    sprintf(str, "%hd", num);
    return str;
}

static inline const char* int2str(int num)
{
    // int：2~4字节 -32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647
    static char str[12];
    sprintf(str, "%d", num);
    return str;
}

static inline const char* float2str(float num)
{
    // float：4字节 1.2E-38 到 3.4E+38
    static char str[12];
    sprintf(str, "%f", num);
    return str;
}

static inline const char* double2str(double num)
{
    // double：8字节 2.3E-308 到 1.7E+308
    static char str[21];
    sprintf(str, "%lf", num);
    return str;
}

static inline const char* ulonglong2str(unsigned long long num)
{
    // unsigned long long：8字节 0 到 18,446,744,073,709,551,615
    static char str[21];
    sprintf(str, "%llu", num);
    return str;
}

static inline const char* str2str(const char* str)
{
    // 直接返回即可
    return str;
}

// 颜色宏代码测试
#define TestColor(obj)\
{\
    println(RED(obj));\
    println(LIGHT_RED(obj));\
    println(GREEN(obj));\
    println(LIGHT_GREEN(obj));\
    println(BLUE(obj));\
    println(LIGHT_BLUE(obj));\
    println(CYAN(obj));\
    println(LIGHT_CYAN(obj));\
    println(PURPLE(obj));\
    println(LIGHT_PURPLE(obj));\
    println(YELLOW(obj));\
    println(LIGHT_YELLOW(obj));\
    println(DARY_GRAY(obj));\
    println(LIGHT_GRAY(obj));\
    println(WHITE(obj));\
}

// 兼容Color两种写法
#define TestColur TestColor

// 原始打印宏，根据obj类型调用不同的打印函数
#define _print(obj) (_Generic((obj),    \
    char:		        print_char,     \
    unsigned char:		print_uchar,    \
                                        \
    short int:	        print_short,    \
    int:		        print_int,      \
    unsigned int:		print_uint,     \
                                        \
    long long:          print_longlong, \
    unsigned long long: print_ulonglong,\
                                        \
    float:		        print_float,    \
    double:		        print_double,   \
                                        \
    const char*:        print_cstr,     \
	char*:		        print_str,      \
                                        \
    int*:               print_p,        \
    long long*:         print_p,        \
    unsigned long long*:print_p,        \
    float*:             print_p,        \
    double*:            print_p,        \
                                        \
    default:            print_void_or_error     \
    )(obj))

// 原始打印换行宏，直接调用打印函数然后打印换行符
#define _println(obj) _print(obj), _print("\n")

// 获取参数个数，最多支持10个参数
#define _PrintMacroArgCount(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, COUNT,...) COUNT
#define PrintMacroArgCount(...) _PrintMacroArgCount("ignored", ##__VA_ARGS__,9,8,7,6,5,4,3,2,1,0)

// 宏黏贴
#define PrintConcat(A, B) _PrintConcat(A, B)
#define _PrintConcat(A, B) A##B

// 打印宏的宏展开，最多支持10个参数
// 原理: print(a, b, c); 展开后变成 _print(a), _print(b), _print(c);
#define print(...) _print_(__VA_ARGS__)
#define _print_(...) PrintConcat(_print_, PrintMacroArgCount(__VA_ARGS__))(__VA_ARGS__)
#define _print_0()                                              printf("")
#define _print_1(_0)                                           _print(_0)
#define _print_2(_0, _1)                                       _print_1(_0), _print(_1)
#define _print_3(_0, _1, _2)                                   _print_2(_0, _1), _print(_2)
#define _print_4(_0, _1, _2, _3)                               _print_3(_0, _1, _2), _print(_3)
#define _print_5(_0, _1, _2, _3, _4)                           _print_4(_0, _1, _2, _3), _print(_4)
#define _print_6(_0, _1, _2, _3, _4, _5)                       _print_5(_0, _1, _2, _3, _4), _print(_5)
#define _print_7(_0, _1, _2, _3, _4, _5, _6)                   _print_6(_0, _1, _2, _3, _4, _5), _print(_6)
#define _print_8(_0, _1, _2, _3, _4, _5, _6, _7)               _print_7(_0, _1, _2, _3, _4, _5, _6), _print(_7)
#define _print_9(_0, _1, _2, _3, _4, _5, _6, _7, _8)           _print_8(_0, _1, _2, _3, _4, _5, _6, _7), _print(_8)
#define _print_10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9)      _print_9(_0, _1, _2, _3, _4, _5, _6, _7, _8), _print(_9)

#define endl ((char)'\n')

// 打印并换行宏的宏展开，最多支持10个参数
// 原理: println(a, b, c); 展开后变成 _println(a), _println(b), _println(c);
#define println(...) _println_(__VA_ARGS__)
#define _println_(...) PrintConcat(_println_, PrintMacroArgCount(__VA_ARGS__))(__VA_ARGS__)
#define _println_0()                                              print("\n")
#define _println_1(_0)                                           _println(_0)
#define _println_2(_0, _1)                                       _println_1(_0), _println(_1)
#define _println_3(_0, _1, _2)                                   _println_2(_0, _1), _println(_2)
#define _println_4(_0, _1, _2, _3)                               _println_3(_0, _1, _2), _println(_3)
#define _println_5(_0, _1, _2, _3, _4)                           _println_4(_0, _1, _2, _3), _println(_4)
#define _println_6(_0, _1, _2, _3, _4, _5)                       _println_5(_0, _1, _2, _3, _4), _println(_5)
#define _println_7(_0, _1, _2, _3, _4, _5, _6)                   _println_6(_0, _1, _2, _3, _4, _5), _println(_6)
#define _println_8(_0, _1, _2, _3, _4, _5, _6, _7)               _println_7(_0, _1, _2, _3, _4, _5, _6), _println(_7)
#define _println_9(_0, _1, _2, _3, _4, _5, _6, _7, _8)           _println_8(_0, _1, _2, _3, _4, _5, _6, _7), _println(_8)
#define _println_10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9)      _println_9(_0, _1, _2, _3, _4, _5, _6, _7, _8), _println(_9)

// 下面是打印各种类型的原始打印函数
static inline void print_char(char num)
{
    printf("%c", num);
}

static inline void print_uchar(unsigned char num)
{
    printf("%c", num);
}

static inline void print_short(short int num)
{
    printf("%hd", num);
}

static inline void print_int(int num)
{
    printf("%d", num);
}

static inline void print_uint(unsigned int num)
{
    printf("%u", num);
}

static inline void print_longlong(long long num)
{
    printf("%lld", num);
}

static inline void print_ulonglong(unsigned long long num)
{
    printf("%llu", num);
}

static inline void print_float(float num)
{
    printf("%f", num);
}

static inline void print_double(double num)
{
    printf("%lf", num);
}

static inline void print_cstr(const char* str)
{
    printf("%s", str);
}

static inline void print_str(char* str)
{
    printf("%s", str);
}

static inline void print_p(void* obj)
{
    printf("%p", obj);
}

static inline void print_void_or_error(void *data)
{
    _print(RED( "print error! or" ));
    _println(RED( "don't have this type to print!" ));
}

// debug宏
#define debug_valuename_to_str(value) #value
#define debug(obj) print(LIGHT_GREEN("debug: "), debug_valuename_to_str(obj)" = ", obj, "\n")

#define WARN_IF(EXP)  \
do                    \
{                     \
    if (EXP)          \
        print(YELLOW("warning: "), #EXP "\n"); \
}while(0)

#define ERR_IF(EXP)   \
do                    \
{                     \
    if (EXP)          \
        print(RED("error: "), #EXP "\n"); \
}while(0)

#define ERR_EXIT_IF(EXP)\
do                    \
{                     \
    if (EXP)          \
    {                 \
        print(RED("error: "), #EXP "\n"); \
        exit(-1);\
    }\
}while(0)

// 打印数组宏

// 打印数组宏控制打印方式
// 0: 数组元素之间用空格隔开
#define printArrTypeSpace 0
// 1: 数组元素之间用换行符隔开
#define printArrTypeln    1
// 2: 打印数组元素和元素下标
#define printArrTypeName  2

// 获取数组长度宏
#define GET_ARR_LEN(arrobj) \
	(_Generic((arrobj),\
    char *:		  strlen((const char *)arrobj),\
    default:      (sizeof(arrobj) / sizeof(arrobj[0]))\
    ))

// 打印数组宏， 其中type是数组的元素之间按照什么方式打印
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

#endif // !__Print_H__