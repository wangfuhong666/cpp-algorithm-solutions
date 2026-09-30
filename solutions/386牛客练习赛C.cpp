#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
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
template <typename T> inline void read(T& x)
{
    x = 0; int f = 1; char ch;
    while ((ch = getchar()) > '9' || ch < '0') if (ch == '-') f = -1;
    while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ '0'), ch = getchar();
    x *= f;
}

void sol()
{
    int n;
    read(n);
    vl arr(n, 0);
    bool is = false;
    rep(i, 0, n)read(arr[i]);
    vl tmp = arr;
    sort(all(tmp));
    vl ret;
    rep(i, 1, n)
    {
        if (tmp[i] == tmp[i - 1])
        {
            if (ret.empty() || ret.back() != tmp[i])ret.pb(tmp[i]);
        }
    }

    if (sz(ret) > 1)
    {
        cout << -1 << '\n';
        return;
    }

    if (sz(ret)==0) 
    {
        if (tmp.back() == n - 1) 
        {
            rep(i, 0, n)
            {
                cout << arr[i] << " \n"[i == n - 1];
            }
        }
        else
        {
            cout << -1 << '\n';
        }
        return;
    }
   
    ll m = ret[0];
    if (tmp.back() > m||tmp.back()>n)
    {
        cout << -1 << '\n';
        return;
    }
    vb vis(m, false);
    vi pos;
    int c = 0;
    rep(i, 0, n)
    {
        if (arr[i] == m)c++;       
        else vis[arr[i]] = true;
    }
    rep(i,0,m)if (!vis[i]) pos.pb(i);
    if (c < 2 * sz(pos))
    {
        cout << -1 << '\n';
        return;
    }
    vl res(n, 0);
    int idx = 0, cnt = 0;
    rep(i, 0, n) 
    {
        if (arr[i] < m)res[i] = arr[i];
        else if (arr[i] == m)
        {
            if (idx < sz(pos)) 
            {
                res[i] = pos[idx], cnt++;
                if (cnt == 2) idx++, cnt = 0;
            }
            else res[i] = m + 1;
        }
    }

    rep(i, 0, n) cout << res[i] << " \n"[i == n - 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    read(t);
    while (t--)sol();
    return 0;
}
