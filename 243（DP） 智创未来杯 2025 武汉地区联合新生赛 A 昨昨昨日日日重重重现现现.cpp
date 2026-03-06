#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
//定义状态：dp[i][j]表示在字符串s的前i个字符中，作为子序列，恰好匹配到缩写t的前j个字符的方案总数。
vector<string>cnt{ "HUST","WHU","HZAU","CCNU","WHUT"};
int dp[N][N];

string s;
int find(string t)
{

    int n = s.size();
    int m = t.size();
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            //状态转移方程
            //dp[i][j]=  dp[i-1][j-1]+dp[i-1][j] (s[i-1]==t[j-1])
            //           dp[i-1][j]              (s[i-1]!=t[j-1])  
            if (s[i - 1] == t[j - 1])dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    sort(cnt.begin(), cnt.end());
    cin >> s;
    vector<int>res;
    for (int i = 0; i < cnt.size(); i++)res.push_back(find(cnt[i]));
    string ret;
    int setnum = -0x3f3f3f3f;
    for (int i = 0; i < cnt.size(); i++)
    {
        if (res[i] > setnum)
        {
            ret = cnt[i];
            setnum = res[i];
        }
    }
    cout << ret << ' ' << setnum;
    return 0;
}
