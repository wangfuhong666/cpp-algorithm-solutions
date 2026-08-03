#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N=1e6+10;
vector<bool>ispr(N,true);
vector<int>pr;
vector<int>phi(N,0);
void getphi(int n)
{
    phi[1]=1;
    ispr[0]=ispr[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(ispr[i])
        {
            pr.push_back(i);
            phi[i]=i-1;
        }
        for(int j=0;j<(int)pr.size();j++)
        {
            int p=pr[j];
            if(1LL*p*i>n)break;
            ispr[i*p]=false;
            if(i%p)
            {
                phi[i*p]=phi[i]*(p-1);
            }
            else
            {
                phi[i*p]=phi[i]*p;
                break;
            }
        }
    }
}
void sol()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0<<'\n';
        return;
    }
    getphi(n);
    ll ans=0;
    for(int i=1;i<n;i++)ans+=2*phi[i];
    cout<<ans+1<<'\n';
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
