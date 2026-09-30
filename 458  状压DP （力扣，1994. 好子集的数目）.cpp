#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ll = long long;
class Solution {
private:
const ll mod = 1e9+7;
 int own[31] = { 
    0b0000000000, // 0
    0b0000000000, // 1
    0b0000000001, // 2
    0b0000000010, // 3
    0b0000000000, // 4
    0b0000000100, // 5
    0b0000000011, // 6
    0b0000001000, // 7
    0b0000000000, // 8
    0b0000000000, // 9
    0b0000000101, // 10
    0b0000010000, // 11
    0b0000000000, // 12
    0b0000100000, // 13
    0b0000001001, // 14
    0b0000000110, // 15
    0b0000000000, // 16
    0b0001000000, // 17
    0b0000000000, // 18
    0b0010000000, // 19
    0b0000000000, // 20
    0b0000001010, // 21
    0b0000010001, // 22
    0b0100000000, // 23
    0b0000000000, // 24
    0b0000000000, // 25
    0b0000100001, // 26
    0b0000000000, // 27
    0b0000000000, // 28
    0b1000000000, // 29
    0b0000000111 // 30
 };
 vector<int>mp;
vector<vector<ll>> dp;
public:

    int numberOfGoodSubsets(vector<int>& nums) 
    {
        dp.assign(1 << 10, vector<ll>(31, -1));
        mp.resize(31);
        for(auto e:nums)
        {
            mp[e]++;
        }
        int ans = 0;
        for(int mask = 1;mask<(1<<10);mask++)
        {
            ans = ans + dfs(mask,30);
            ans%=mod;
        }
        ans = 1LL*ans*qpow(2,mp[1])%mod;
        ans%=mod;
        return ans;
    }
private:
// 质数: 29 23 19 17 13 11 7 5 3 2
// 位置: 9 8 7 6 5 4 3 2 1 0
    ll dfs(int mask,int id)
    {
        if(dp[mask][id]!=-1)return dp[mask][id];
        if(mask==0)return dp[mask][id] = 1;
        if(id<2) return dp[mask][id] = 0;
        int ans = dfs(mask,id-1)%mod;;
        if(own[id] && ((mask & own[id]) == own[id]))ans = ans + 1LL*mp[id] * dfs(mask^own[id],id-1)%mod;
        return dp[mask][id] = ans % mod;
        
    }
    ll qpow(ll a,ll b)
    {
        a%=mod;
        ll res = 1;
        while(b)
        {
            if(b&1)res = res*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return res % mod;
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
