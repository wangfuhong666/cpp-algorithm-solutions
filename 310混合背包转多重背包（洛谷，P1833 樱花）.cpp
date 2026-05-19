#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main()
{
    int hh1, mm1, hh2, mm2;
    scanf("%d:%d %d:%d", &hh1, &mm1, &hh2, &mm2);
    int n;
    cin >> n;
    int T = hh2 * 60 + mm2 - hh1 * 60 - mm1;
    vector<int>arrt(N, 0), arrc(N, 0);
    int idx = 1;
    while (n--)
    {
        int t, c, p;
        cin >> t >> c >> p;
        if (!p)p = 1000;
        int num = 1;
        while (p)
        {   
            if (p < num)break;
            arrt[idx] = num * t;
            arrc[idx++] = num * c;
            p -= num;
            num <<= 1;
        }
        if (p)
        {
            arrt[idx] = p * t;
            arrc[idx++] = p * c;
        }
    }
    vector<long long>dp(T + 1, 0);
    for (int i = 1; i < idx; i++)
    {
        for (int j = T; j >= arrt[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - arrt[i]] + arrc[i]);
        }
    }
    cout << dp[T];
    return 0;
}
