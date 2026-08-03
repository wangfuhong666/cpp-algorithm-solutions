#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (auto& num : arr)cin >> num;
        vector<int>dp(6, 0);
        for (int i = 0; i < 6; i++)
        {
            if (arr[0] == i + 1)dp[i] = 0;
            else dp[i] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            vector<int>nextdp(6, 0x3f3f3f3f);
            for (int j = 0; j < 6; j++)
            {
                int cur = j + 1;
                int cost;
                if (arr[i] == cur)cost = 0;
                else cost = 1;
                for (int k = 0; k < 6; k++)
                {
                    int tem = k + 1;
                    if (cur != tem && cur + tem != 7)nextdp[j] = min(nextdp[j], dp[k] + cost);
                }
            }
            dp = nextdp;
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 6; i++)ans = min(ans, dp[i]);
        cout << ans << '\n';
    }
    return 0;
}
