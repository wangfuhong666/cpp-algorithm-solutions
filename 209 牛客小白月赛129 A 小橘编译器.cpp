#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int m = INT_MAX;
    for (int i = 0; i < s.size()-1; i++)
    {
        if (s.size() < 2 || (s[i] =='/' &&s[i + 1] == '/'))
        {
            m = i;
            break;
        }
    }
    if (m == INT_MAX)cout << s;
    else if (m == 0)cout << "null";
    else
    {
        for (int j = 0; j < m; j++)cout << s[j];
    }
    return 0;
}
