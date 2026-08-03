#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+1),mp(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int j;
        cin>>j;
        mp[j]=i;
    }
    bool ju=true;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=mp[i])
        {
            ju=false;
            break;
        }
    }
    if(ju)cout<<"Yes";
    else cout<<"No";
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
