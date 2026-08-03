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
    vector<int>arr(n), dp(n, 0);
    for (auto& num : arr)cin >> num;
    int ans = INT_MIN; 
    for (int i = 0; i < n; i++)
    {
        int ret = 1;
        for (int j = 0; j < i; j++)if (arr[j] < arr[i])ret = max(ret, dp[j] + 1);
        dp[i] = ret;
        ans = max(ans, ret);
        
    }
    cout << ans;
    return 0;

}
