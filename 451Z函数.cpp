#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const ll mod = (1LL<<32);

void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>z(n,0);
    int l = 0,r = 0;
    for(int i = 1;i < n;i++)
    {
        if(i <= r)
            z[i] = min(r - i + 1,z[i-l]);
        while(i + z[i] <n&&s[z[i]] == s[i + z[i]])
            z[i] ++;
        if(i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] -1;
        }
    }
    for(int i = 0;i < n; i++)cout<<z[i]<<' ';
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
