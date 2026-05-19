#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
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
    int s, d, hp;
    read(s);
    read(d);
    read(hp);
    vp arr(n + 1);
    rep(i, 1, n + 1)read(arr[i].fi), read(arr[i].se);
    rep(i, 1, n + 1)
    {
        int a = arr[i].fi;
        int k = arr[i].se;
        if (min(a, 3 )* s >= hp)
        {
            cout << "Yes" << '\n';
            cout << i;
            return;
        }
        if ((k + d - 1) / d > min(5 - a, 3))
        {
            cout << "No"<<'\n';
            return;
        }
        hp -= min(a, 3 - (k + d - 1) / d) * s;
        if (hp <= 0)
        {
            cout << "Yes" << '\n';
            cout << i;
            return;
        }
    }
    cout << "No" << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //read(t);
    while (t--)sol();
    return 0;
}
