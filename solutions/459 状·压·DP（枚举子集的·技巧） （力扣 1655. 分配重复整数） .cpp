#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define all(x) (x).begin(),(x).end()
class Solution {
    vector<int>mp;
    vector<int>cnt;
    vector<vector<int>>dp;
    int n;
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        sort(all(nums));
        vector<int>tem=nums;
        tem.erase(unique(all(tem)),tem.end());
        mp.assign(tem.size(),0);
        for(int i =0, j = 0;i < nums.size();i++)
        {
            if(tem[j]==nums[i])mp[j]++;
            else 
            {
                j++;
                mp[j]++;
            }
        }
        n = quantity.size();
        dp.assign((1<<n),vector<int>(mp.size(),-1));
        cnt.assign((1<<n),0);
        for(int i = 0;i < n;i++)
        {
            int s = (1<<i);
            for(int j = 0;j < s;j++)
            {
                cnt[s|j]= cnt[j] + quantity[i];
            }
        }
        return dfs((1<<n)-1,0);
    }
private:
    bool dfs(int mask,int id)
    {
        if(mask==0)return true;
        if(id >= mp.size()) return false;
        if(dp[mask][id]!=-1)return dp[mask][id];
        bool ans = dfs(mask,id+1);
        for(int j = mask;j>0;j = (j-1)&mask)
        {
            if(ans)return dp[mask][id] = true;
            if(cnt[j] <= mp[id])
            {
                if(dfs(mask^j,id+1))return dp[mask][id] = true;
            }
        }
        return dp[mask][id] = false;
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
