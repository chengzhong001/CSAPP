#include "common.h"
#include <bitset>
#include <iostream>
#include <string.h>
// 2-5
void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;

    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}
// 2-5
void test_2_5()
{
    test_show_bytes(12345);
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
}
// 2-6
void test_2_6()
{
    int i_num = 3510593;
    std::cout << "num int hex value:";
    show_int(i_num); // little endian: 41 91 35 00
    std::cout << "num float hex value:";
    show_float(i_num); // little endian: 04 45 56 4a

    int i_hex_val = 0x00359141;
    int f_hex_val = 0x4a564504;

    std::cout << "i_hex_val: " << std::bitset<sizeof(int) * 8>(i_hex_val) << "\n";
    std::cout << "i_hex_val: " << std::bitset<sizeof(float) * 8>(f_hex_val) << "\n";
}

// 2-7
void test_2_7()
{
    const char *s = "abcdefxyzABDCEFXYZ";
    show_bytes((byte_pointer)s, strlen(s));
}

// 2-10
void inplace_swap(int *x, int *y)
{

    std::cout << "entter: x:" << *x << " y:" << *y << "\n";
    *y = *x ^ *y;
    std::cout << "step1: x:" << *x << " y:" << *y << "\n";
    *x = *x ^ *y;
    std::cout << "step2: x:" << *x << " y:" << *y << "\n";
    *y = *x ^ *y;
    std::cout << "step3: x:" << *x << " y:" << *y << "\n";
}
// 2-11
void reverse_array(int a[], int cnt)
{
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--)
    // first 只能小于 否则会对于数组中一个位置的值会交换
    {
        std::cout << "first: " << first << " last: " << last << "\n";
        inplace_swap(&a[first], &a[last]);
    }
}

void reverse_array_test()
{
    int a[] = {1, 2, 3, 4};
    reverse_array(a, 4);
    for (int i : a)
        std::cout << i << " ";

    int b[] = {1, 2, 3, 4, 5};
    reverse_array(b, 5);
    for (int i : b)
        std::cout << i << " ";

    std::cout << "\n";
    int i1 = 4;
    int i2 = 4;

    inplace_swap(&i1, &i2);
    std::cout << "i1: " << i1 << " i2: " << i2 << "\n";
}
// 2-12
void test_2_12()
{
    int x = 0x87654321;
    // result = 0x00000021, other bit is 0
    printf("0x000000%.2x\n", (x & 0xff));

    printf("0x%x\n", (x ^ ~0xff));
    printf("0x%x\n", (x | 0xff));

    // std::cout << std::bitset<8>(x & 0xff) << "\n" ;
}

// 2-13
int bis(int x, int m) { return x | m; }
int bic(int x, int m) { return x & ~m; }

int bool_or(int x, int y)
{
    int result = bis(x, y);
    return result;
}

int bool_xor(int x, int y)
{
    int result = bis(bic(x, y), bic(y, x));
    return result;
}
// 2_14
void test_2_14()
{
    int x = 0x66;
    int y = 0x39;
    // bit op
    printf("0x%.2x & 0x%.2x = 0x%.2x\n", x, y, x & y);
    printf("0x%.2x | 0x%.2x = 0x%.2x\n", x, y, x | y);
    printf("~0x%.2x | ~0x%.2x = 0x%.2x\n", x, y, ~x | ~y);
    printf("0x%.2x & !0x%.2x = 0x%.2x\n", x, y, x & !y);

    // logic op
    printf("0x%.2x && 0x%.2x = 0x%.2x\n", x, y, x && y);
    printf("0x%.2x || 0x%.2x = 0x%.2x\n", x, y, x || y);
    printf("!0x%.2x || !0x%.2x = 0x%.2x\n", x, y, !x || !y);
    printf("0x%.2x && ~0x%.2x = 0x%.2x\n", x, y, x && ~y);
}

// 2~15
int is_equal(int x, int y)
{
    return !(x ^ y);
}

char *num_to_bin(int value, int len)
{
    // char data[9];
    char *data = (char *)malloc(len);
    if (value < 0)
        memset(data, '1', 8);
    else
        memset(data, '0', 8);
    char *temp=(char *)malloc(len);
    int remainder;
    int index = 0;
    char ch;
    while (value != 0)
    {
        value = value / 2;
        remainder = value % 2;
        len -= 1;
        // std::cout << "remainder: "<< remainder << " ";

        // data[index] = remainder + 48;
        ch = remainder + 48;
        strcat(temp, &ch);
        std::cout << temp <<" ";
        index += 1;
    }
    memcpy(data, temp, strlen(temp));
    std::cout<< data<<"\n";
    return data;
}

int main(int argc, char const *argv[])
{
    /* code */
    // test_2_14();
    // std::cout << is_equal(-1,2);
    // int a= -1;
    // int num = 0b0110001110010101;
    // unsigned int u_num = 0b0110001110010101;
    // std::cout << std::bitset<16>(num >> 4) << "\n";
    // std::cout << std::bitset<16>(u_num >> 4) << "\n";
    // std::cout << std::bitset<16>(-2) << "\n";

    // printf("%s\n", num_to_bin(-10, 8));
    // printf("%s\n", num_to_bin(10, 8));
    num_to_bin(10, 8);
    // std::cout << std::bitset<8>(-10) << "\n";
    // std::cout << std::bitset<8>(10) << "\n";

    return 0;
}
