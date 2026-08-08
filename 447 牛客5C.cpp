#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
void sol()
{
    int b;
    cin>>b;
    if(b==2||b%2)
    {
        cout<<"-1\n";
        return;
    }
    if(b==4)
    {
        cout<<"0 1 2 3\n";
        cout<<"1 3 0 2\n";
        cout<<"2 0 3 1\n";
        return;
    }
    vector<int>p(b+1),q(b+1),r(b+1);
    int tem=0;
    for(int i = 1;;i+=2)
    {
        if(i>b)break;
        p[i] = tem++;
        q[i] = p[i] + 2;
    }
    tem = b/2;
    for(int i = 2;;i+=2)
    {
        if(i>b)break;
        if(tem==b-2)
        {
            p[i] = tem;
            q[i] = 0;          
        }
        else if(tem==b-1)
        {
            p[i] = tem;
            q[i] = 1;            
        }
        else
        {
            p[i] = tem;
            q[i] = p[i] + 2;
        }
        tem++;
    }
    for(int i = b;i>=1;i--)
    {
        r[i] += p[i] + q[i];
        if(r[i]>=b)
        {
            r[i-1] += r[i] / b;
            r[i] %= b;
        }
    }
    for(int i = 1;i <= b;i++) cout<<p[i]<<(i<b?" ":"\n");
    for(int i = 1;i <= b;i++) cout<<q[i]<<(i<b?" ":"\n");
    for(int i = 1;i <= b;i++) cout<<r[i]<<(i<b?" ":"\n");
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
