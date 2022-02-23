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

// 10进制转2进制
char *dec2bin(int value, int len)
{
    char *data = (char *)malloc(len);
    while (len >= 0)
    {
        len -= 1;
        // printf("%d", len);
        data[len] = (value & 1) + '0';
        value = value >> 1;
    }
    return data;
}

// 16进制转2进制
char *hex2bin(const char *hex, int len = 0)
{
    const int ch_bit = 4;    // 单个字符占用位数
    int i = strlen(hex) - 1; // 倒序

    len = (len == 0) ? strlen(hex) * ch_bit : len;
    char *data = (char *)malloc(len);
    memset(data, '0', len); // data填充 0

    while (len >= 0)
    {
        len -= ch_bit;
        if (hex[i] >= '0' && hex[i] <= '9')
            memcpy(&data[len], dec2bin(hex[i] - '0', ch_bit), ch_bit);
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            // data[len] = hex[i] - 'a' + 10;
            memcpy(&data[len], dec2bin(hex[i] - 'a' + 10, ch_bit), ch_bit);
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            memcpy(&data[len], dec2bin(hex[i] - 'A' + 10, ch_bit), ch_bit);
        i--;
    }
    return data;
}
// 16进制转10进制
int hex2dec(const char *hex)
{ // 2AF5
    size_t len = strlen(hex);
    int result = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
            result = result * 16 + (hex[i] - '0');
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            result = result * 16 + (hex[i] - 'a' + 10);
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            result = result * 16 + (hex[i] - 'A' + 10);
    }
    return result;
}
// 2进制转10进制
int bin2dec(const char *bin)
{
    size_t len = strlen(bin);
    int result = 0;
    for (size_t i = 0; i < len; i++)
    {
        // result = (bin[i] == '1') ? result * 2 + 1 : result * 2;
        result = result * 2 + (bin[i] - '0');
    }
    return result;
}

char *dec2binary(int num, int len)
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

    return (char *)data;
}

// char 类型逻辑移位
char *logic_shift(char num, int bit)
{
    unsigned char a = (unsigned char)num >> bit;
    return dec2bin(a, sizeof(char) * 8);
}

// char类型算术移位
char *arithmetic_shift(char num, int len)
{
    char a = num >> len;
    return dec2bin(a, sizeof(char) * 8);
}

// int类型逻辑移位
char *logic_shift(int num, int len)
{
    unsigned a = (unsigned int)num >> len;
    return dec2bin(a, sizeof(int) * 8);
}

// int类型算术移位
char *arithmetic_shift(int num, int len)
{
    int a = num >> len;
    return dec2bin(a, sizeof(int) * 8);
}
