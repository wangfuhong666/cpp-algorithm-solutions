#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
int m(int a,int b,int c)
{
    ll sum=a+b+c;
    int maxn=max({a,b,c});
    int minn = min({a,b,c});
    return (int)(sum-maxn-minn);
}
const int inf=1e9;
const int k =100;
const int n=10;

void sol()
{

    vector<int>a(n);
    for(int i = 0;i < n;i++)a[i]=rand()%inf;
    cout<<"原数组为：";
    for(int i = 0;i < n;i++)
    {
        cout<<a[i]<<" " ;   
    }
    cout<<'\n';
    for(int h=1;h<=k;h++)
    {
        cout<<"第"<<h<<"次变换的结果为";
        vector<int>b(n);
        for(int i = 0;i<n;i++)
        {
            b[i]=m(a[i],a[(i+1)%n],a[(i-1+n)%n]);
        }
        a=b;  
        for(int i = 0;i < n;i++)
        {
            cout<<a[i]<<" " ;   
        }   
        cout<<'\n';
    }
    cout<<"\n\n\n\n";
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
