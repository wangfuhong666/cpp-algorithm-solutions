#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int>arr;
    int a = 10;
    arr.push_back(1);    
    arr.push_back(a);
    for (int i = 1; i <= 5; i++)
    {
        if (i <= 3)cout << string(2 - i + 1, ' ') << string(2 * i - 1, '*') << '\n';
        else
        {
            int j = i - 3;
            cout << string(j, ' ') << string(2 * (2 - j) + 1, '*') << '\n';
        }
    }
    return 0;
}
