#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const double d=0.0105;
//0.0104015----0.010505895
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
void dfs(int root)
{
    cout<<1<<' ';
    dfs(2 * root);
    dfs(2*root+1);
}
void dp()
{

    stack<int>st;


}
//递归
//stack 1e3 + 10
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
