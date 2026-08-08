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
    int len =(1<<n) -1;
    string s;
    cin>>s;
    s=' '+s;
    vector<int>a(len+1,0),b(len+1,0);
    set<int>st;
    for(int i = 1;i<=len;i++)
    {
        int x  = s[i] - '0';
        a[i]=x;
        if(x==1)st.insert(i);
    }
    while(st.size()>1)
    {
        int y =*st.begin();
        st.erase(st.begin());
        int x =*st.begin();
        st.erase(st.begin());
        a[x] = a[y] = 0;
        b[x] = y;
        int z = x^y;
        if(a[z] == 0)
        {
            a[z] = 1;
            st.insert(z);
        }
        else
        {
            a[z] = 0;
            st.erase(z);
        }

    }
    for(int i = 1;i<=len;i++)
    {
        cout<<b[i]<<(i<len?" ":"\n");
    }
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
