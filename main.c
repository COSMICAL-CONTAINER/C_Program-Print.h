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

    debug(char_a);

    WARN_IF(char_a == '0');
    ERR_IF(2 == 2);
    ERR_EXIT_IF(3 == 3);
    WARN_IF(char_a == 1);

    return 0;
}
