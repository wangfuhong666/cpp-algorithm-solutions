#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, w;
    cin >> w >> n;
    vector<int>arrv(n + 1, 0), arrw(n + 1);
    vector<int>arr(1,0);
    vector<vector<int>>adj(n+1);
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        arrv[i] = x;
        arrw[i] = x * y;
        if (z)adj[z].push_back(i); 
        else arr.push_back(i);      
    }
    int n1 = arr.size();
    vector<vector<int>>dp(n1 + 1, vector<int>(w + 1, 0));
    for (int i = 1; i < n1; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = dp[i - 1][j];
            int k = adj[arr[i]].size();
            if (j < arrv[arr[i]])continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j - arrv[arr[i]]] + arrw[arr[i]]);
            if (k == 0)continue;
            
            if (k == 1)
            {
                if (j >= arrv[adj[arr[i]][0]]+arrv[arr[i]])dp[i][j] = max(dp[i][j], dp[i - 1][j - arrv[adj[arr[i]][0]]- arrv[arr[i]]] + arrw[adj[arr[i]][0]] + arrw[arr[i]]);
            }
            else
            {
                if (j >= arrv[adj[arr[i]][0]] + arrv[arr[i]])dp[i][j] = max(dp[i][j], dp[i - 1][j - arrv[adj[arr[i]][0]] - arrv[arr[i]]] + arrw[adj[arr[i]][0]] + arrw[arr[i]]);
                if (j >= arrv[adj[arr[i]][1]] + arrv[arr[i]])dp[i][j] = max(dp[i][j], dp[i - 1][j - arrv[adj[arr[i]][1]] - arrv[arr[i]]] + arrw[adj[arr[i]][1]] + arrw[arr[i]]);
                if (j >= arrv[adj[arr[i]][0]] + arrv[adj[arr[i]][1]] + arrv[arr[i]]) 
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - arrv[adj[arr[i]][0]] - arrv[arr[i]] - arrv[adj[arr[i]][1]]] + arrw[adj[arr[i]][0]] + arrw[adj[arr[i]][1]] + arrw[arr[i]]);

            }
        }
    }
    cout << dp[n1-1][w];
    return 0;
}