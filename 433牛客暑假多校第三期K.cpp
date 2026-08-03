#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(),(x).end()
void sol()
{
    int n;
    cin>>n;
    vector<ll>x(n),y(n);
    for(int i=0;i<n;i++)cin>>x[i]>>y[i];
     for(int i=1;i<n-1;i++)
     {
        ll ax = x[i] - x[i - 1];
        ll ay = y[i] - y[i - 1];

        ll bx = x[i + 1] - x[i];
        ll by = y[i + 1] - y[i];
        ll ju = ax * by - ay * bx;   
        if (ju > 0)cout << "LEFT ";     
        else if (ju < 0)cout << "RIGHT ";       
        else cout << "STRAIGHT ";
                     
     }
     cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)sol();
    return 0;
}
