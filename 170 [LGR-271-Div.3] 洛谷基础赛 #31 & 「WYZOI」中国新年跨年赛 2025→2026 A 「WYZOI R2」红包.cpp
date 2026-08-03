#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    long long sum = 0LL;
    for (int i = 0; i < n; i++)
    {
        string s;
        long long a;
        cin >> s >> a;
        if (s == "Q")sum += a;
    }
    cout << sum;
    return 0;
}
