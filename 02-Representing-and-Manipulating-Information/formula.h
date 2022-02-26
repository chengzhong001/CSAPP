#ifndef __FORMULA_H__
#define __FORMULA_H__

#include <stdlib.h>
#include <string.h>

unsigned B2U(char *data, int len)
{
    size_t len = strlen(data);
    int result = 0;
    for (size_t i = 0; i < len; i++)
    {
        // result = (bin[i] == '1') ? result * 2 + 1 : result * 2;
        result = result * 2 + (data[i] - '0');
    }
    return result;
}

#endif