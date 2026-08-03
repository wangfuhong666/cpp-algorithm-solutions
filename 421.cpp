#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#include <bits/stdc++.h>
using namespace std;
void sol()
{
    const int M = 50;
    vector<vector<int>> dp(M + 1, vector<int>(M + 1, 0));

    dp[0][0] = 0; 

    for (int x = 0; x <= M; x++)
    {
        for (int y = 0; y <= M; y++)
        {
            if (x == 0 && y == 0) continue;

            bool win = false;

            if (x >= 1 && dp[x - 1][y] == 0) win = true;
            if (x >= 2 && dp[x - 2][y] == 0) win = true;
            if (y >= 1 && dp[x][y - 1] == 0) win = true;
            if (y >= 2 && dp[x][y - 2] == 0) win = true;

            dp[x][y] = win;
        }
    }

    for (int x = 0; x <= M; x++)
    {
        for (int y = 0; y <= M; y++)
        {
            cout << (dp[x][y] ? "W " : "L ");
        }
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--)sol();
    return 0;
}
