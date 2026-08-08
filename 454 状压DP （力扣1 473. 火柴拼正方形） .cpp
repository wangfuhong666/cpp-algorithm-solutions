#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ll = long long;
class Solution {
private:
    vector<int>a;
    vector<int>dp;
    int n;
    ll len;
public:
    bool makesquare(vector<int>& matchsticks) {
        a = matchsticks;
        n = matchsticks.size();
        ll sum = 0;
        dp.resize(1<<n);
        for(auto  e:a)sum+=e;
        if(sum%4!=0)return false;
        len = sum/4;
        return dfs(((1<<n)-1),0,4);
    }
private:
    bool dfs(int mask,ll cur,int rest)
    {
        if(rest==0)
            return mask==0;
        if(dp[mask]) return dp[mask] ==1;
        bool ans = false;
        for(int i= 0;i < n;i++)
        {
            if((mask&(1<<i))&&a[i] + cur<=len)
            {
                if(a[i] + cur ==len) ans = dfs(mask^(1<<i),0,rest-1);
                else ans = dfs(mask^(1<<i),a[i] + cur,rest);
            }
            if(ans)
                break;
        }
        dp[mask] = (ans?1:-1);
        return ans;
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
