#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N=6e3+10;
struct node
{
    ll no;
    ll yes;
};
vector<ll>val(N,0);
vector<vector<int>>adj(N);
vector<bool>isroot(N,true);
int n;
node dfs(int root)
{
    //if(adj[root].size()==0)return {0,val[root]};
    ll yes=val[root],no=0;
    for(auto e:adj[root])
    {
        node c=dfs(e);
        yes+=c.no;
        no+=max(c.yes,c.no);
    }
    return {no,yes};
}
void sol()
{
    cin>>n;
    int tem=n-1;
    for(int i=1;i<=n;i++)cin>>val[i];
    while(tem--)
    {
        int l,k;
        cin>>l>>k;
        adj[k].push_back(l);
        isroot[l]=false;
    }
    int root=-1;
    for(int i=1;i<=n;i++)if(isroot[i])root=i;
    node res=dfs(root);
    cout<<max(res.no,res.yes);
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
