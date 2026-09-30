#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const ll mod = 998244353;
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<bool>a(2*n+10,false);
    bool ok = true;
    for(int i = 1; i <= m;i++)
    {
        int x;
        cin>>x;
        if(x > 2 * n - 1)
        {
            ok = false;

        }
        else a[x] = true;
    }
    if(!ok)
    {
        cout<<"0\n";
        return;
    }
  vector<vector<int>> dp(2 * n + 1, vector<int>(n + 1, 0));

    dp[0][0] = 1;

    for(int i = 1; i <= 2 * n; i++)
    {
        for(int j = 0; j <= min(i, n); j++)
        {

            if(j >= 1)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            }

            if(!a[i] && j <= i - 1 && j >= i - j)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
        }
    }
    cout << dp[2 * n][n] << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)sol();
    return 0;
}
