#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a, b, d;
    cin >> a >> b >> d;
    int n = (b - a) / d + 1;
    for (int i = 1; i <= n; i++)cout << a + (i - 1) * d << ' ';
    return 0;
}
