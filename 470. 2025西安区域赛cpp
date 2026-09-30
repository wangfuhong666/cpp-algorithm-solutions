#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define all(x) (x).begin() , (x).end()

int calc(vector<int>&a)
{
    int n = a.size();
    int s = 0;
    for(int i = 0;i <n;i++)
    {
        if(s >=a[i])s++;
        else s--;
    }
    return s;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i <n;i++)
    {
        cin>>a[i];    
    }
    sort(all(a));
    int s1 = calc(a);
    sort(all(a),greater<int>());
    int s2 = calc(a);
    cout<<s1<<" "<<s2<<'\n';

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
