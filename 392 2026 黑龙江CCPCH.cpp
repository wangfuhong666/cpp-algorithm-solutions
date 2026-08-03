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
void sol()
{
    string s;
    cin>>s;
    ll x=0;
    for(auto e:s)
    {
        if(e=='.')continue;
        x=x*10+e-'0';
    }
    __int128 y=(__int128)4*x-300;
    string res="";
    while(y)
    {
        res+='0'+(y%10);
        y/=10;
    }
    reverse(all(res));
    int n=res.size();
    if(n==1)cout<<"0.0"<<res<<'\n';
    else if(n==2)cout<<"0."<<res<<'\n';
    else 
    {
        rep(i,0,n)
        {
            if(i==n-2)cout<<'.';
            cout<<res[i];
        }
        cout<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)sol();
    return 0;
}
