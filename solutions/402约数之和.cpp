#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
ll sumdiv(int n)
{
    ll sum=0LL;
    for(int i=1;i<n/i;i++)
    {
        if(n%i==0)
        {
            sum+=i;
            if(i!=n/i)sum+=n/i;
        }
    }
    return sum;
}
void sol()
{
    ll n;
    cin>>n;
    cout<<sumdiv(n);
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
