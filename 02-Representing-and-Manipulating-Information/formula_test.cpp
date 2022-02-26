#include "formula.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    /* code */
    const char* bin = "1101";
    // std::cout << B2U(bin) << std::endl;
    std::cout << B2U(bin) << std::endl;
    std::cout << B2T(bin) << std::endl;
    std::cout << U2B(-3, 5) << std::endl;
    std::cout << T2B(-3, 5) << std::endl;
    int x = 0b1010;
    std::cout << T2U(x, 4) << std::endl;
    std::cout << U2T(x, 4) << std::endl;
    return 0;
}
