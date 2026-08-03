#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const double d=0.0105;
void sol()
{
    int n;
    cin>>n;
    cout << 2 * n << '\n';
    for(int i=1;i<=n;i++)
    {
        double x=i/10*d;
        double y=i%10*d;
        printf("%.10lf %.10lf %.10lf\n",x,y,0.0);
        printf("%.10lf %.10lf %.10lf\n",x,y,1.0);
    }
}
int main()
{
    //ios::sync_with_stdio(false);
   // cin.tie(nullptr);
   // cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)sol();
    return 0;
}
