#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int inf=10;
const int k =20;
const int n=6;
int mex(int a,int b,int c)
{
    for(int i=0;;i++)
    {
        if(i!=a && i!=b && i!=c) return i;
    }
}
void sol()
{

    vector<int>a{0,1,0,2,2,3};

    //for(int i = 0;i < n;i++)a[i]=rand()%inf;
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
            b[i]=mex(a[i],a[(i+1)%n],a[(i-1+n)%n]);
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
    srand(time(nullptr));
    int t=1;
    //cin>>t;
    while(t--)sol();
    return 0;
}
