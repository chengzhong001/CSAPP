// 2-4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

void print_binary(unsigned int number)
{
    if (number >> 1)
    {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

char *decimal2bin(int value, int len)
{
    char *data = (char *)malloc(len);
    while (len >= 0)
    {
        len -= 1;
        data[len] = (value & 1) + 48;
        value = value >> 1;
    }
    return data;
}

char *decimal2binary(int num, int len)
{
    char *result = new char[32];
    memset(result, 0, 32);
    int i = 0;
    while (num)
    {
        result[i++] = num & 1 ? '1' : '0';
        num >>= 1;
    }
    return result;
}

char *complement(int value, int len)
{
    int num = -15;
    char *data = (char *)malloc(len);
    char *temp = (char *)malloc(len);
    for (int i = 0; i < len; i++)
    {
        temp[i] = num & 1; //与1就是显示它本身，此时的num是补码,把第i位存入数组
        num = num >> i;    // num的补码  往右移i位
    }
    for (int i = len - 1; i >= 0; i--)
        data[len - i - 1] = temp[i] + 48;

    return data;
}

// char类型算术移位
char *arithmetic_shit(char num, int bit)
{
    unsigned char a = (unsigned char)num >> bit;
    return decimal2bin(a, sizeof(char) * 8);
}
// char 类型逻辑移位
char *logic_shit(char num, int bit)
{
    char a = num >> bit;
    return decimal2bin(a, sizeof(char) * 8);
}

// int类型算术移位
char *arithmetic_shit(int num, int bit)
{
    unsigned a = (unsigned int)num >> bit;
    return decimal2bin(a, sizeof(int) * 8);
}

// int类型逻辑移位
char *logic_shit(int num, int bit)
{
    char a = num >> bit;
    return decimal2bin(a, sizeof(int) * 8);
}
