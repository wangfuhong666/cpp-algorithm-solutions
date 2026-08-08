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
    unordered_set<int>st;
    while(n--)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    if((int)st.size()<=3)cout<<"YES\n";
    else cout<<"NO\n";
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
