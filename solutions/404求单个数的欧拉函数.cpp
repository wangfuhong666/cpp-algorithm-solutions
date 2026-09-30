#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;

ll phi(int n)
{
    ll ans=n;
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
            ans-=ans/i;
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans-=ans/n;
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    cout<<phi(n);
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
