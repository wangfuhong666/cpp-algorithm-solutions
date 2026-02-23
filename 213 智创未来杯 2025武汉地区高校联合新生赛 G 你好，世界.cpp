#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, len;
    cin >> n >> len;
    bool judge = false;
    //true (1<<n)>=len
    if (n > 31)judge = true;
    else if ((1 << (n - 1)) >= len)judge = true;
    else judge = false;
    if (judge)cout << string(len, '1');
    else
    {
        string s((1 << (n - 1)), '1');
        int num = len - (1 << (n - 1));
        int e = 1;
        while (num--)
        {
            if (e == 1)s += '0';
            else s += '1';
            e *= -1;
        }
        cout << s;
    }
    return 0;
}
