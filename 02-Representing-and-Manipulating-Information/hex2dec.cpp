#include <iostream>
#include <math.h>
#include <assert.h>
#include <stdio.h>
int bin2dec(const char *bin_num)
{

    int length = strlen(bin_num);
    int result = 0, digit = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        if ((i == 0 && bin_num[i] == '0') || (i == 1 && tolower(bin_num[i]) == 'x'))
            continue;
        if (bin_num[i] != '1' && bin_num[i] != '0')
            std::cout << "error binary digit:" << bin_num[i] << '\n';
        if (bin_num[i] == '1')
            result += pow(2, digit);
        digit += 1;
    }
    return result;
}

void dec2bin(int dec_num){
    char* result;
    while (dec_num!=0)
    {
        dec_num = dec_num / 2;
        // std::cout << dec_num % 2;
        printf("%s", (dec_num % 2));
    }
    
   
}

int main(int argc, char const *argv[])
{
    const char *str = "0x100000000";
    std::cout << (bin2dec(str)) << "\n";
    dec2bin(10);
    return 0;
}
