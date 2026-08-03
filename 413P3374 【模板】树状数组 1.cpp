#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define lc p << 1
#define rc p << 1 | 1
const int N = 5e5 + 10;
struct node
{
    int l, r;
    ll sum, lazy;
} tr[N << 2];
vector<int> arr(N, 0);
void pushup(int p)
{
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}
void lazy(int p, ll k)
{
    int l = tr[p].l;
    int r = tr[p].r;
    tr[p].sum += (r - l + 1) * k;
    tr[p].lazy += k;
}
void pushdown(int p)
{
    ll k = tr[p].lazy;
    lazy(lc, k);
    lazy(rc, k);
    tr[p].lazy = 0;
}
void build(int p, int l, int r)
{
    tr[p] = {l, r, 0, 0};
    if (l == r)
    {
        tr[p].sum = arr[l];
        return;
    }
    int mid = (ll)(l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}
ll query(int p, int x, int y)
{
    int l = tr[p].l;
    int r = tr[p].r;
    if (x <= l && r <= y)
    {
        return tr[p].sum;
    }
    pushdown(p);
    ll sum = 0;
    int mid = (ll)(l + r) >> 1;
    if (x <= mid)
        sum += query(lc, x, y);
    if (y >= mid + 1)
        sum += query(rc, x, y);
    return sum;
}
void modify(int p, int x, int y, int k)
{
    int l = tr[p].l;
    int r = tr[p].r;
    if (x <= l && r <= y)
    {
        lazy(p, k);
        return;
    }
    pushdown(p);
    int mid = (ll)(l + r) >> 1;
    if (x <= mid)
        modify(lc, x, y, k);
    if (y >= mid + 1)
        modify(rc, x, y, k);
    pushup(p);
}
void sol()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    build(1, 1, n);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            ll k;
            cin >> x >> k;
            modify(1, x, x, k);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query(1, x, y) << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
        sol();
    return 0;
}
