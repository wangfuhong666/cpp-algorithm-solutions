#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int>a,b;
int n;
ll calc()
{
    ll res=0LL;
    for(int i =0;i<n;i++)
    {
        res+=abs(a[i]-b[i]);
    }
    return res;
}
void sol()
{
    
    cin>>n;
    a.clear();
    b.clear();
    a.resize(n);
    b.resize(n);
    int maxa=INT_MIN,mina=INT_MAX;
    int maxb=INT_MIN,minb=INT_MAX;
    int maxacount=0,maxbcount=0,minacount=0,minbcount=0;
    int maxaidx=0,maxbidx=0,minaidx=0,minbidx=0;
    for(int i = 0;i<n;i++)
    {
        cin>>a[i];
        if(maxa<a[i])
        {
            maxa=a[i];
            maxacount=1;
            maxaidx=i;
        }
        else if(maxa==a[i])maxacount++;
        if(mina>a[i])
        {
            mina=a[i];
            minacount=1;
            minaidx=i;
        }
        else if(mina==a[i])minacount++;
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        if(maxb<b[i])
        {
            maxb=b[i];
            maxbcount=1;
            maxbidx=i;
        }
        else if(maxb==b[i])maxbcount++;
        if(minb>b[i])
        {
            minb=b[i];
            minbcount=1;
            minbidx=i;
        }
        else if(minb==b[i])minbcount++;
    }
    if(maxb>maxa||minb<mina)
    {
        cout<<"-1\n";
        return;
    }
    if(maxa==mina)
    {
        if(maxb==minb&&maxb==maxa)cout<<"0\n";
        else cout<<"-1\n";
        return;
    }
    if(maxacount>1||minacount>1)
    {
        cout<<calc()<<'\n';
        return;
    }
    if(n==2)
    {
        if(a[0]>a[1])
        {
            if(b[0]>=b[1])cout<<calc()<<'\n';
            else cout<<"-1\n";
        }
        else if(a[0]==a[1])
        {
            if(a[0]==b[0]&&a[0]==b[1])cout<<"0\n";
            else cout<<"-1\n";
        }
        else
        {
            if(b[0]<=b[1])cout<<calc()<<'\n';
            else cout<<"-1\n";
        }
        return;
    }
    if(maxaidx!=minbidx||minaidx!=maxbidx)
    {
        cout<<calc()<<'\n';
        return;
    }
    ll res=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i]==maxa||a[i]==mina)continue;
        ll tmp1=abs(a[i]-maxb);
        tmp1+=abs(maxb-b[i]);
        ll tmp2=abs(a[i]-minb);
        tmp2+=abs(minb-b[i]);
        res=min(res,min(tmp1,tmp2)-abs(a[i]-b[i]));
    }
    cout<<calc()+res<<'\n';
}
int main()
{
    int t;
    cin>>t;
    while(t--)sol();
    return 0;
}