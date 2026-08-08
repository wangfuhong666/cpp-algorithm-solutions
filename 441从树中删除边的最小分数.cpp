#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N =1e3+10;
class Solution {
vector<vector<int>>adj;
vector<int>dfn,sz,sum,a;
int total;
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        adj.resize(N);
        dfn.resize(N);
        sz.resize(N);
        sum.resize(N);
        a=nums;
        
        for(auto e:edges)
        {
            int a = e[0];
            int b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int id=1;
        dfs(0,-1,id);
        int ans=INT_MAX;
        int m=edges.size();
        total=sum[1];
        for(int i=0;i<m;i++)
        {
            for(int j = i + 1;j<m;j++)
            {
                int a=max(dfn[edges[i][0]],dfn[edges[i][1]]);
                int b=max(dfn[edges[j][0]],dfn[edges[j][1]]);
                if(a>b)swap(a,b);
                if(b<a+sz[a])
                {
                    int p1=sum[b];
                    int p2=sum[a]^sum[b];
                    int p3=total^sum[a];
                    int mx = max({p1, p2, p3});
                    int mn = min({p1, p2, p3});
                    ans = min(ans, mx - mn);
                    
                }
                else
                {
                    int p1=sum[b];
                    int p2=sum[a];
                    int p3=total^p1^p2;
                    int mx = max({p1, p2, p3});
                    int mn = min({p1, p2, p3});
                    ans = min(ans, mx - mn);
    
                }
                
            }
        }
        return ans;
    }
private:
    int dfs(int root,int fa,int &id)
    {
        int card=id++;
        dfn[root]=card;
        int su=a[root];
        int num=0;
        for(auto v:adj[root])
        {
            if(v==fa)continue;
            int cid=id;
            su^=dfs(v,root,id);
            num+=sz[cid];
        }
        sz[card]=num+1;
        return sum[card] = su;
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
