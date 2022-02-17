// 2-4
// #include <bitset>
#include <iostream>
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

void print_binary(unsigned int number) {
    if (number >> 1) {
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
