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

unsigned T2U(int value, int len)
{
    return B2U(dec2bin(value, len));
}

int U2T(unsigned value, int len)
{
    return B2T(dec2bin(value, len));
}

#endif