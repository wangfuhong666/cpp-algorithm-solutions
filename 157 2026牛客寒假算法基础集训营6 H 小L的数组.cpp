#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int maxsize = 1 << 11;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>arr1(n), arr2(n);
    for (auto& num : arr1)cin >> num;
    for (auto& num : arr2)cin >> num;
    vector<bool>dp(maxsize, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        vector<bool>dpnext(maxsize, false);
        for (int j = 0; j < maxsize; j++)
        {
            if (dp[j])
            {
                int tem1 = max(0, j - arr1[i]);
                dpnext[tem1] = true;
                int tem2 = j ^ arr2[i];
                dpnext[tem2] = true;
            }
            
        }
        dp = dpnext;
    }
    int ans = 0;
    for (int i=maxsize-1; i>=0; i--)
    {
        if (dp[i])
        {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}
