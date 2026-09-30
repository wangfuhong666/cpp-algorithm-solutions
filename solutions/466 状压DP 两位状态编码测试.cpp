#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
int getinfo(int s, int j)
{
    return (s >> (2 * j)) & (2 * 2 - 1);
}
int setinfo(int s,int j,int t)
{
    return (s&(~((2*2-1)<<(2*j))))|(t<<(2*j));
}
void sol()
{
    int a =0b00000001100;
    cout<<setinfo(a,0,2);
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
