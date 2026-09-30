#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll mod = 376544743;
int n, m, k;
vector<vector<int>> a;
vector<int>aa(2,0);

int getinfo(int s, int j)
{
    return (s >> (2 * j)) & (2 * 2 - 1);
}
//0110101100111100
//
int setinfo(int s,int j,int t)
{
    return (s&(~((2*2-1)<<(2*j))))|(t<<(2*j));
}

int different(int s,int t)
{
    for(int i  = 0;i < m;i++)
    {
        if(getinfo(s,i)==getinfo(t,i))
        {
            return 0;
        }
    }
    return 1;
}

// ll dfs(int i, int j, int mask)
// {
//     if (i == n -  1)return different(aa[1],mask) % mod;
//     if(j==m) return dfs(i+1,0,mask) % mod;
//     ll ans = 0LL;
//     for(int s = 0;s<k;s++)
//     {
//         if(getinfo(mask,s)!=s&&(j==0||getinfo(mask,j-1)!=s))
//         {
//             ans = (ans + dfs(i,j+1,setinfo(mask,j,s))) % mod;
//         }
//     }
//     return  ans % mod;
// }

void sol()
{
    cin >> n >> m >> k;
    a.assign(2, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
        cin >> a[0][j];
    for (int j = 0; j < m; j++)
        cin >> a[2 - 1][j];
    if (k == 2)
    {
        if (((n - 2) - (1) + 1) % 2 == 1)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[0][j] != a[2 - 1][j])
                {
                    cout << 0;
                    return;
                }
            }
            cout << 1;
            return;
        }
        else
        {
            for (int j = 0; j < m; j++)
            {
                if (a[0][j] == a[2 - 1][j])
                {
                    cout << 0;
                    return;
                }
            }
            cout << 1;
            return;
        }
    }
    for (int j = 0; j < m; j++)
    {
        aa[0] = setinfo(aa[0], j, a[0][j]);
        aa[1] = setinfo(aa[1], j, a[1][j]);
    }

    for(int j = 1;j < m;j++)
    {
        if(getinfo(aa[0],j)==getinfo(aa[0],j - 1)||getinfo(aa[1],j)==getinfo(aa[1], j -1))
        {
            cout<<0;
            return;
        }

    }
    vector<vector<ll>>dp(m+1,vector<ll>(1LL<<(2 * m),0));
    vector<ll>pre((1<<(2*m)),0);
    for(int mask = 0;mask <(1<<(2*m));mask++)pre[mask] = different(mask ,aa[1]);
    for(int i= n - 2;i > 0;i--)
    {
        for(int mask = 0;mask <(1<<(2*m));mask++)dp[m][mask] = pre[mask];
        for(int j = m-1;j>=0;j--)
        {
             for(int mask = 0;mask <(1<<(2*m));mask++)
             {
                ll ans = 0LL;
                for(int s = 0;s < k;s++)
                {
                    if(getinfo(mask,j)!=s&&(j==0||getinfo(mask,j-1)!=s))
                    {
                        ans = (ans +dp[j+1][setinfo(mask,j,s)])%mod;
                    }
                }
                dp[j][mask] = ans %mod;
            }
        }
        for(int mask = 0;mask <(1<<(2*m));mask++)
        {
            pre[mask] =dp[0][mask];
        }
    }
    cout<<pre[aa[0]];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
        sol();
    return 0;
}
