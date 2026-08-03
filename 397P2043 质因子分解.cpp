#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=1e6+10;
vector<int>pr(N,0);
void depr(int n)
{
    for(int i=2;i<=n/i;i++)
    {
        int cnt=0;
        while(n%i==0)
        {
            cnt++;
            n/=i;
        }
        pr[i]+=cnt;
    }
    if(n>1)pr[n]++;
}
void sol()
{
    int n;
    cin>>n;
    if(n<=1)
    {
        cout<<"0 0\n";
        return;
    }
    for(int i=2;i<=n;i++)
    {
        depr(i);
    }
    for(int i=2;i<=n;i++)
    {
        if(pr[i])
        {
            cout<<i<<' '<<pr[i]<<'\n';
        }
    }
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
