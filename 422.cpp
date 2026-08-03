#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const ll mod=1e9+7;
void sol()
{

    for(int x=0;x<3;x++)
    {
        for(int y=0;y<=10;y++)
        {
            x%=3;
            int r=0;
            if(x==1)r++;
            if(x==2)r--;
            string s="WWL";
            int z=(y+x+r)%3;
            cout<<s[z]<<' ';
            
        }
        cout<<'\n';
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
