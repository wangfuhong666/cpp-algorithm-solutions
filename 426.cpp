#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N=1e6+10;
vector<bool>ispr(N,true);
vector<int>pr;
void start(int n)
{
    ispr[0]=ispr[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(ispr[i])pr.push_back(i);
        for(int j=0;j<pr.size();j++)
        {
            if(1LL*i*pr[j]>n)break;
            ispr[i*pr[j]]=false;
            if(i%pr[j]==0)break;
        }
    }
}
void sol()
{
    int n;
    cin>>n;
    start(n);
    vector<bool>dp(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(!dp[i-1])dp[i]=true;
        else
        {
            for(int j=0;j<pr.size()&&pr[j]<=i;j++)
            {
                if(!dp[i-pr[j]])
                {
                    dp[i]=true;
                    break;
                }
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        cout<<i<<' ';
        if(dp[i])cout<<"Alice"<<' ';
        else cout<<"Bob"<<' ';
        if(i%16==0)cout<<'\n';
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
