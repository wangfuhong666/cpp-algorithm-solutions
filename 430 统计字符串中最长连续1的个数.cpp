#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    int l=0,r=0;
    int res=0;
    while(r<n)
    {
        if(s[r]=='0')l=r+1;
        else res=max(res,r-l+1);
        r++;
    }
    cout<<res;
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
