#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define rep(x,a,b) for(int x=(a);x<(b);x++)
struct node
{
    ll u,d,c;
};
const int N=28;
vector<node>arr(N);
int n,m;
ll a,b;
ll maxn=-1;
vector<int>path;
vector<ll>sum(3,0);
void dfs(int x)
{
    if(sum[2] > m) return;
    if(x==n) 
    {
        if(path.empty()) return;
        ll a1,b1;
        ll c=0;
        a1=sum[0];
        b1=sum[1];
        c=sum[2];
        if(c>m|| (__int128)a*b1!= (__int128)b*a1)return;
        maxn=max(maxn,a1);
        return;
    }
    path.push_back(x);
    sum[0]+=arr[x].u;
    sum[1]+=arr[x].d;
    sum[2]+=arr[x].c;
    dfs(x+1);
    //int sz1=path.size();
    //rep(i,0,sz1)cout<<path[i]<<" \n"[i==sz1-1];
    path.pop_back();
    sum[0]-=arr[x].u;
    sum[1]-=arr[x].d;
    sum[2]-=arr[x].c;
    dfs(x+1);
    //int sz2=path.size();
    //rep(i,0,sz2)cout<<path[i]<<" \n"[i==sz2-1];
}
void sol()
{
    cin>>n>>m>>a>>b;
    for(int i=0;i<n;i++)cin>>arr[i].u>>arr[i].d>>arr[i].c;
    dfs(0);
    cout<<maxn<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--)sol();
}
int main()
{
    

    return 0;
}