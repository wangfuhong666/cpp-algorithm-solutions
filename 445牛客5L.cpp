#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<ll>>a(n+10,vector<ll>(m+10,0));
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <=m;j++)
            cin>>a[i][j];
    if(a[1][1]!=a[n][m])
    {
        cout<<"-1\n";
        return;
    }
    if(n == 1 || m == 1)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(a[i][j] != a[1][1])
                {
                    cout << "-1\n";
                    return;
                }
            }
        }

        cout << "0\n";
        return;
    }
    ll k =a[2][1] + a[1][2] - 2 * a[1][1];
    if(k<0)
    {
        cout<<"-1\n";
        return;
    }   
    ll t= a[1][1] + k;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <=m;j++)
        {
            
            if(t-a[i][j] < 0)
            {
                cout << "-1\n";
                return;
            }
            a[i][j]=t-a[i][j];
        }
    for(int d = 3;d <= n + m;d++)
    {
        ll down = 0LL;
        int l = max(1, d - m - 1);
        int r = min(n, d - 1);
        for(int i = l; i <= r; i++)
        {
            int j = d - i;
            ll right = a[i][j] -down;
            if(right<0||right>a[i][j-1])
            {
                cout<<"-1\n";
                return;
            }
            down = a[i][j-1] -right;
            if(down<0)
            {
                cout<<"-1\n";
                return;                
            }
        }
        if(down!=0)
        {
            cout<<"-1\n";
            return;
        }
    }
    cout<<k<<'\n';
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
