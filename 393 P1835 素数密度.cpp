#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define rep(x,a,b) for(int x=(a);x<(b);x++)
#define per(x,a,b) for(int x=(a);x>=(b);x--)
using vi=vector<int>;
using vl=vector<ll>;
using vb=vector<bool>;
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
const int N= 1e6+10;
vb ispr(N,true);
vi pr;
void getpr(int n)
{
    ispr[0]=ispr[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(ispr[i])pr.pb(i);
        for(ll j=0;j<pr.size();j++)
        {
            if(i*pr[j]>n)break;
            ispr[i*pr[j]]=false;
            if(i%pr[j]==0)break;
        }
    }
}
void sol()
{
    ll l,r;
    cin>>l>>r;
    getpr(sqrt(r));
    //for(auto e:pr)cout<<e<<' ';
    //cout<<'\n';
    vb arr(r-l+1,true);
    if(l==1)l=2;
    for(int i =0;i<pr.size();i++)
    {
        ll x=pr[i];
        for(ll j=max(2LL,(l+x-1)/x);x*j<=r;j++)arr[x*j-l]=false;
    }
    //for(auto e:arr)cout<<e<<' ';
    //cout<<'\n';
    int cnt=0;
    rep(i,0,r-l+1)cnt+=arr[i];
    cout<<cnt<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
   // cin>>t;
    while(t--)sol();
    return 0;
}
