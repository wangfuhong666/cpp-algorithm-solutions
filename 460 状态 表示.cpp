#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<ll>a(m);
    for(int i = 0;i < m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[i]|=(1<<x);
        a[i]|=(1<<y);
    }
    ll res=0LL;
    for(ll mask = 0;mask < (1LL<<n);mask++)
    {
        bool flag = true;
        for(int i = 0;i < m;i++)
        {
            if((mask&a[i])==a[i])
            {
                flag = false;
                break;
            }
        }
        res+=flag;
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
