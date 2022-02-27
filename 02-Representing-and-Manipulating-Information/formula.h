#ifndef __FORMULA_H__
#define __FORMULA_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 二进制转无符号数
unsigned B2U(const char *data)
{
    size_t len = strlen(data);
    int result = 0;
    for (size_t i = 0; i < len; i++)
        // result = (data[i] == '1') ? result * 2 + 1 : result * 2;
        result = result * 2 + (data[i] - '0');

    return result;
}

// 二进制转有符号数
int B2T(const char *data)
{
    size_t len = strlen(data);
    int value = (data[0] == '0') ? 0 : 1;
    int result = 0;
    for (size_t i = 1; i < len; i++)
    {
        result = result * 2 + (data[i] - '0');
        value = value * 2;
    }

    return result - value;
}
// 无符号数转二进制
char *U2B(unsigned value, int len)
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
// 有符号数转二进制
char *T2B(int value, int len)
{
    char *data = (char *)malloc(len);
    while (len >= 0)
    {
        len -= 1;
        data[len] = (value & 1) + '0';
        value = value >> 1;
    }
    return data;
}
// 十进制转二进制
char *dec2bin(int value, int len)
{
    char *data = (char *)malloc(len);
    while (len >= 0)
    {
        len -= 1;
        data[len] = (value & 1) + '0';
        value = value >> 1;
    }
    return data;
}

// 有符号转无符号数
unsigned T2U(int value, int len)
{
    // T2U(x,w) = x + 2^w   x < 0
    // T2U(x,w) = x         x >= 0
    return B2U(dec2bin(value, len));
}

// 无符号转有符号数
int U2T(unsigned value, int len)
{
    // U2T(u,w) = u - 2^w   u > TMax
    // U2T(u,w) = u         u <= TMax
    return B2T(dec2bin(value, len));
}
// 计算x的y次方
int pow(int x, int y)
{
    int result = 1;
    for (int i = 0; i < y; i++)
        result *= x;
    return result;
}

#endif