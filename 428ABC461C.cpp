#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
vector<vector<ll>>a;
bool cmp(int x,int y)
{
    return a[x][0]>a[y][0];
}
void sol()
{
    //nlogn
    int n,k,m;
    cin>>n>>k>>m;
    a.resize(n+1);
    unordered_set<int>st;
    vector<int>h;//下标
    for(int i=1;i<=n;i++)
    {
        int c,v;
        cin>>c>>v;
        a[c].push_back(v);
        if(st.count(c))continue;
        h.push_back(c);
        st.insert(c);
    }
    for(int i=0;i<h.size();i++)
    {
        int idx=h[i];
        sort(a[idx].begin(),a[idx].end(),greater<ll>());
    }
    ll res=0;
    sort(h.begin(),h.end(),cmp);
    for(int i=0;i<m;i++)
    {
        int idx=h[i];
        res+=a[idx][0];
        k--;
        if(k<=0)break;
    }
    if(k==0)
    {
        cout<<res;
        return;
    }
    vector<int>tem;
    for(int i=0;i<h.size();i++)
    {
        int idx=h[i];
        for(int j =(i<m?1:0);j < a[idx].size();j++)tem.push_back(a[idx][j]);
    }
    sort(tem.begin(),tem.end(),greater<int>());
    for(int i=0;i<tem.size();i++)
    {
        res+=tem[i];
        k--;
        if(k<=0)break;
    }
    cout<<res;
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
