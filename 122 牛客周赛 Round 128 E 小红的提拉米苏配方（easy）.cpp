#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
int main()
{
    string s;
    cin >> s;
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)if (s[i] == '1')count++;
    if (count < 2)
    {
        cout << s;
        return 0;
    }
    if (count % 2 == 0)
    {
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                res++;
                if (res > count / 2)cout << '2';
            }
            else
            {
                cout << s[i];
            }
        }
        return 0;
    }
    int cnt1 = 0;
    int cnt = 0;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            cnt1++;

            if (cnt1 <= (count + 1) / 2 && s[i + 1] == '2')
            {
                idx = i;
                break;
            }
            if (cnt1 == (count + 1) / 2)idx = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            cnt++;
            if (i == idx)cout << s[i];
            if (cnt > (count + 1) / 2)
            {
                cout << '2';
            }
        }
        else
        {
            cout << s[i];
        }
    }
    return 0;
}