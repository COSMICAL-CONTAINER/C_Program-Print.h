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
