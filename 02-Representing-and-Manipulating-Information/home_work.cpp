#include <iostream>
#include <bitset>
#include "common.h"

int main()
{
    //   int a = 0xFFFFFFFF;
    //   std::cout << std::hex << ((unsigned) a >> 1) << std::endl; // 逻辑右移
    //   std::cout << std::hex << (a >> 1) << std::endl; // 算数右移
    //   std::cout << arithmatic_shit(a,1, 32) << std::endl;

    // int b = 0b10010101;
    // // //   std::cout << std::hex << (b >> 1) << std::endl;
    // std::cout << std::bitset<8>((char)b >> 4) << std::endl;
    // std::cout << std::bitset<8>(b >> 4) << std::endl;

    //   int c = (char)b>>4;
    //   std::cout << arithmatic_shit(b, 4) << std::endl ;

    // std::cout << (int)b << std::endl;

    std::cout << ((-2147483647-1u)  < -2147483647 ) << std::endl;
    return 0;
}
