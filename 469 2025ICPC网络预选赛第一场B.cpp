#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
ll gcd(ll a,ll b)
{
    a = llabs(a);
    b = llabs(b);
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    ll m = n - k;
    vector<vector<int>>a(n+1,vector<int>(n+1,0));
    for(int j = 1;j<=n;j++)
    {
        for(int i = j+1;i<=n;i++)
        {
            a[i][j] = gcd(abs(i - j),n);
        }
    }
    vector<pii>b;;
    for(int i = 1;i<=n;i++)
    {
        int cnt = 0;
        for(int j = 1;j<i;j++)cnt +=a[i][j];
        for(int j = i+1;j<=n;j++)cnt +=a[j][i];
        b.push_back({cnt,i});
    }
    sort(b.begin(),b.end(),greater<pii>());
    for(int i = 0;i<k;i++)cout<<b[i].second<<' ';

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
