#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;、
class Solution {
private:
    vector<int>a;
    vector<int>dp;
    int n;
public:
    int minTransfers(vector<vector<int>>& transactions) {
        vector<int>tem(12);
        for(auto e:transactions)
        {
            int fi = e[0];
            int li = e[1];
            int mo = e[2];
            tem[fi]-=mo;
            tem[li] += mo;
        }
        for(auto e:tem)
            if(e)
                a.push_back(e);
        n = a.size();
        dp.assign((1<<n),-1);
        return n - dfs(0,0);
    }
private:
    int dfs(int mask,int sum)
    {
        if(dp[mask]!=-1)return dp[mask];
        if(mask==(1<<n)-1)return 0;
        if(sum==0)
        {
            for(int i = 0;i<n;i++)
            {
                if(mask&(1<<i))continue;
                return dp[mask] = 1 + dfs(mask|(1<<i),sum-a[i]);
            }
        }
        else
        {
            int ans = 0;
            for(int i = 0;i<n;i++)
            {
                if(mask&(1<<i))continue;
                ans = max(ans,dfs(mask|(1<<i),sum-a[i]));
            }    
            return dp[mask] = ans;            
        }
        return 0;
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
