#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> m >> n;
    vector<vector<int>>adj(N);
    vector<int>arrv(n + 1, 0), arrw(n + 1, 0);
    vector<int>arr;
    unordered_set<int>st;
    for (int i = 1; i <= n; i++)
    {
        cin >> arrv[i] >> arrw[i];
        int x;
        cin >> x;
        adj[x].push_back(i);
        if (!st.count(x))
        {
            arr.push_back(x);
            st.insert(x);
        }
    }
    sort(arr.begin(), arr.end());
    int u = arr.size();
    vector<vector<long long>>dp(u + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= u; i++)
    {
        for(int j=0;j<=m;j++)
        {
            long long tem = dp[i - 1][j];
            for (auto e : adj[arr[i - 1]])
            {
                if (j >= arrv[e])tem = max(tem, dp[i - 1][j - arrv[e]] + arrw[e]);
            }
            dp[i][j] = tem;
        }
        
    }
    cout << dp[u][m];
    return 0;
}
//空间压缩
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> m >> n;
    vector<vector<int>>adj(N);
    vector<int>arrv(n + 1, 0), arrw(n + 1, 0);
    vector<int>arr;
    unordered_set<int>st;
    for (int i = 1; i <= n; i++)
    {
        cin >> arrv[i] >> arrw[i];
        int x;
        cin >> x;
        adj[x].push_back(i);
        if (!st.count(x))
        {
            arr.push_back(x);
            st.insert(x);
        }
    }
    sort(arr.begin(), arr.end());
    int u = arr.size();
    vector<long long>dp(m + 1, 0);
    for (int i = 1; i <= u; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            long long tem = dp[j];
            for (auto e : adj[arr[i - 1]])
            {
                if (j >= arrv[e])tem = max(tem, dp[j - arrv[e]] + arrw[e]);
            }
            dp[j] = tem;
        }

    }
    cout << dp[m];
    return 0;
}
