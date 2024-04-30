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

    TestColor(num5);

    print(num1, num2, num3, num4, num5, "123", 'y');
    println(str1, str2, RED("c"));

    return 0;
}
