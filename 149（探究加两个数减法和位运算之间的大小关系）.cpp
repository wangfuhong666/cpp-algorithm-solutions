#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 0; i <= 10; i++)
    {
        for (int j = 0; j <= 10; j++)
        {
            printf("A = %d , B = %d : A + B = %d,A | B = %d,A ^ B = %d,A & B = %d,|A - B| = %d\n", i, j, i + j, i | j, i ^ j, i & j, abs(i - j));
        }
    }

    return 0;
}
