#ifndef __Print_H__
#define __Print_H__

#include <stdio.h>

#define print(obj) (_Generic((obj),\
    char:		print_char,\
    short int:	print_short,\
    int:		print_int,\
    float:		print_float,\
    double:		print_double,\
    const char*:print_cstr,\
	char *:		print_str)(obj))

#define println(obj) \
	(_Generic((obj),\
    char:		print_char,\
    short int:	print_short,\
    int:		print_int,\
    float:		print_float,\
    double:		print_double,\
    const char*:print_cstr,\
	char *:		print_str)(obj)    ,    print("\n"))

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


// void print_char(char num);
// void print_short(short int num);
// void print_int(int num);
// void print_float(float num);
// void print_double(double num);
// void print_cstr(const char *str);
// void print_str(char *str);

#endif // !__Print_H__