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
const int N=1e6+10;
vector<bool>ispr(N,true);
vector<int>pr;
void getpr(int n)
{
    ispr[0]=ispr[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(ispr[i])pr.push_back(i);
        for(int j=0;j<pr.size();j++)
        {
            if(i*pr[j]>n)break;
            ispr[i*pr[j]]=false;
            if(i%pr[j]==0)break;
        }
    }
}

 void sol()
 {
    int n;
    cin>>n;
    getpr(n);
    for(int i = 0;i < (int)pr.size(); i++)
    {
        int cnt=0;
        ll q=1;
        for(int j=1;j<=n;j++)
        {
            q*=pr[i];
            if(q>n)break;
            cnt+=n/q;
        }
        if(cnt==0)continue;
        cout<<pr[i]<<' '<<cnt<<'\n';
    }
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
