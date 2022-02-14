#include <iostream>
#include <bitset>
#include <stdio.h>

// 2-10
void inplace_swap(int *x, int *y)
{

    std::cout << "entter: x:" << *x << " y:" << *y << "\n";
    *y = *x ^ *y;
    std::cout << "step1: x:" << *x << " y:" << *y << "\n";
    *x = *x ^ *y;
    std::cout << "step2: x:" << *x << " y:" << *y << "\n";
    *y = *x ^ *y;
    std::cout << "step3: x:" << *x << " y:" << *y << "\n";
}
// 2-11
void reverse_array(int a[], int cnt)
{
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--)
    // first 只能小于 否则会对于数组中一个位置的值会交换
    {
        std::cout << "first: " << first << " last: " << last << "\n";
        inplace_swap(&a[first], &a[last]);
    }
}

void reverse_array_test()
{
    int a[] = {1, 2, 3, 4};
    reverse_array(a, 4);
    for (int i : a)
        std::cout << i << " ";

    int b[] = {1, 2, 3, 4, 5};
    reverse_array(b, 5);
    for (int i : b)
        std::cout << i << " ";

    std::cout << "\n";
    int i1 = 4;
    int i2 = 4;

    inplace_swap(&i1, &i2);
    std::cout << "i1: " << i1 << " i2: " << i2 << "\n";
}
// 2-12
void test_2_12()
{
    int x = 0x87654321;
    // result = 0x00000021, other bit is 0
    printf("0x000000%.2x\n", (x & 0xff));

    printf("0x%x\n", (x ^ ~0xff));
    printf("0x%x\n", (x | 0xff));

    // std::cout << std::bitset<8>(x & 0xff) << "\n" ;
}

int main(int argc, char const *argv[])
{
    test_2_12();
    return 0;
}
