#include "show_bytes.h"
#include <bitset>
#include <iostream>
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

int main(int argc, char const *argv[])
{
    test_show_bytes(12345);
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);

    // 2-6
    int i_num = 3510593;
    std::cout << "num int hex value:";
    show_int(i_num); // little endian: 41 91 35 00
    std::cout << "num float hex value:";
    show_float(i_num); // little endian: 04 45 56 4a

    int i_hex_val = 0x00359141;
    int f_hex_val = 0x4a564504;

    std::cout << "i_hex_val: " << std::bitset<sizeof(int) * 8>(i_hex_val) << "\n";
    std::cout << "i_hex_val: " << std::bitset<sizeof(float) * 8>(f_hex_val) << "\n";

    // 2-7
    const char *s = "abcdefxyzABDCEFXYZ";
    show_bytes((byte_pointer)s, strlen(s));

    return 0;
}
