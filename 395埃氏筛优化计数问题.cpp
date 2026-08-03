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
int cntpr(int n)
{
    if(n<=1)return 0;
    vb ispr(n+1,true);
    ispr[0]=ispr[1]=false;
    int cnt=(ll)(n+1)/2;
    for(ll i=3;i*i<=n;i+=2)
    {
        if(!ispr[i]) continue;
        for(ll j=i * i;j <= n;j += 2 * i)
        {
            if(ispr[j])
            {
                cnt--;
                ispr[j] = false;
            }
        }
    }
    return cnt;
}
 void sol()
 {
    int n;
    cin>>n;
    cout<<cntpr(n)<<'\n';
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
