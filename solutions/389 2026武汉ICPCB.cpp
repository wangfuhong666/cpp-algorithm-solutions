#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ump unordered_map
#define ms multiset
#define st set
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vp vector<pii>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
template <typename T>
inline void read(T &x)
{
    x = 0;
    int f = 1;
    char ch;
    while ((ch = getchar()) > '9' || ch < '0')
        if (ch == '-')
            f = -1;
    while (ch >= '0' && ch <= '9')
        x = x * 10 + (ch ^ '0'), ch = getchar();
    x *= f;
}
bool dfs(int n, int m, vi a, vp b, int pos, int pi)
{
    if (pi == 1)
    {
        bool tmp = b[pos].se == 1;
        rep(i, 0, n)
        {
            if (a[i])
            {
                a[i] = 0;
                continue;
            }
            if (tmp)
                a[i] = 2;
            else
                a[i] = 1;
        }
        pos+=1;
    }
    int x = 0;
    rep(j, pos, m)
    {
        if (b[j].fi != 2)return true;     
        x = gcd(x, b[j].se);
    }
    rep(i, 0, n) a[i] = gcd(a[i], x);
    int tem = a[0];
    rep(i, 1, n)
    {
        if (a[i] != tem)return false;   
    }
    return true; 
}
void sol()
{
    int n, m;
    read(n);
    read(m);
    vi a(n);
    rep(i, 0, n) read(a[i]);
    vp b(m);
    rep(i, 0, m) read(b[i].fi), read(b[i].se);
    int tem = a[0];
    bool f1 = true;
    bool j2 = a[0] == 0;
    rep(i, 1, n)
    {
        if (a[i] != tem)
            f1 = false;
        if (!a[i])
            j2 = true;
    }
    int cnt0 = 0;

    rep(i, 0, m) if (b[i].fi == 0) cnt0++;

    if (f1 || cnt0 > 1 || n == 1)
    {
        cout << "Yes\n";
        return;
    }

    int i = 0;
    int cnt1 = 0;

    while (i < m && b[i].fi == 1)
    {
        cnt1++;
        i++;
    }

    if (i == m && cnt1)
    {
        if (j2)
            cout << "No\n";
        else
            cout << "Yes\n";
        return;
    }

    if (i > 0)
    {
        bool tmp = b[i - 1].se == 1;
        rep(i, 0, n)
        {
            if (cnt1 % 2)
            {
                if (a[i])
                {
                    a[i] = 0;
                    continue;
                }
                if (tmp)
                    a[i] = 2;
                else
                    a[i] = 1;
            }
            else
            {
                if (!a[i])
                    continue;
                if (tmp)
                    a[i] = 2;
                else
                    a[i] = 1;
            }
        }
    }
    if(b[i].fi==0)
    {
        b[i].fi = 2;
        bool fl1=dfs(n,m,a,b,i,1);
        bool fl2=dfs(n,m,a,b,i,2);
        if(fl1||fl2)cout<<"Yes\n";
        else cout<<"No\n";
        return;
    }

    if(dfs(n,m,a,b,i,2))cout<<"Yes\n";
    else cout<<"No\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    read(t);
    while (t--)
        sol();
    return 0;
}
