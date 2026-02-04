#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
const int m = 1e5;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= m; i++)
    {
        if (n * i % 10 == 0)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}