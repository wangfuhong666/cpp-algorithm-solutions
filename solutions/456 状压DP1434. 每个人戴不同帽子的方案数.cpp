#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ll = long long;

class Solution {
private:
    int dp[1<<10][45];
    const ll mod = 1e9+7;
    vector<int>like;
    int n;
    int m;
public:
    int numberWays(vector<vector<int>>& hats) {
        memset(dp, -1, sizeof(dp));
        like.resize(45);
        n = (int)hats.size();
        m = 0;
        for(int i = 0;i < n ; i++)
        {
            for(auto e:hats[i])
            {
                like[e]|=(1<<i);
                m = max(m,e);
            }
        }
        return dfs(0,0)%mod;
    }
private:
    int dfs(int mask,int id)
    {
        
        if(dp[mask][id]!=-1)return dp[mask][id];
        if(mask == (1 << n) - 1)
            return dp[mask][id] = 1;
        if(id>m)return 0;
        int st = like[id];
        int ans = dfs(mask,id+1)%mod;
        for(int i = 0;i<n;i++)
        {
            if(mask&(1<<i))continue;
            if(st&(1<<i))
            {
                ans=ans+dfs(mask|(1<<i),id+1)%mod;
                ans%=mod;
            }
        }
        return dp[mask][id] = ans;
    }
};
void sol()
{

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
