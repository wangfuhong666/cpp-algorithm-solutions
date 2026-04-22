#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& dp)
    {
        //dp[i][j]={dp[i-1][j]+1     (matrix[i][j]==1)
        //         { 0               (matrix[i][j]==0)
        //         {matrix[i][j]      (i==0)
        int n = dp.size();
        int m = dp[0].size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dp[i][j] == 1)dp[i][j] += dp[i - 1][j];
            }
        }
        for (int i = 0; i < n; i++)sort(dp[i].begin(), dp[i].end(), greater<int>());
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)ans = max(ans, dp[i][j] * (j + 1));
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int T;
    //cin >> T;
    //while (T--)
    //{

    //}
    
    return 0;
}

