#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N=1000000+10;
vector<int>val(N,0),l(N,0),r(N,0);
int n;
struct node
{
    bool isbst;
    int maxsize;
    int maxn;
    int minn;
};
node dfs(int root)
{
    if(root==0)return {true,0,INT_MIN,INT_MAX};  
    bool ju=false;
    node infol=dfs(l[root]);
    node infor=dfs(r[root]);
    int maxnum=max(infol.maxn,infor.maxn);
    int minnum=min(infol.minn,infor.minn);
    int maxsize=max(infol.maxsize,infor.maxsize);
    if(infol.isbst==true&&infor.isbst==true&&infol.maxn<val[root]&&val[root]<infor.minn)
    {
        ju=true;
        maxsize=max(maxsize,infol.maxsize+infor.maxsize+1);
    }
    return {ju,maxsize,max(maxnum,val[root]),min(minnum,val[root])};
    
}
void sol()
{
    int root;
    cin>>n>>root;
    int tem=n;
    while(tem--)
    {
        int fa,lc,rc;
        cin>>fa>>lc>>rc;
        l[fa]=lc;
        r[fa]=rc;
        val[fa]=fa;
    }
    cout<<dfs(root).maxsize;

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
