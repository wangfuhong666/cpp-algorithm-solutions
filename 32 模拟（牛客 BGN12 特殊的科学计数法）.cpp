#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include<vector>
using namespace std;

int main()
{
    vector<int>arr;
    int ch;
    while ((ch = getchar()) != '\n')
    {
        if ((char)ch == '\n')break;
        arr.push_back((int)ch - '0');
    }
    int a = arr[0], b = arr[1], c = arr.size() - 1, d = arr[2];
    if (arr[2] >= 5 && arr[2] <= 9)
    {
        d = 0;
        b++;
    }
    if (b >= 10)
    {
        b -= 10;
        a++;
    }
    if (a >= 10)
    {
        a /= 10;
        c++;
    }
    printf("%d.%d*10^%d", a, b, c);
    return 0;
}
// 64 Œª ‰≥ˆ«Î”√ printf("%lld")