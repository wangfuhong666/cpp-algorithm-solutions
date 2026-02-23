#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int size1 = 3e5 + 5;
struct L
{
    int l, r, p;
};
vector<long long>D(size1, 0);
vector<long long>res(size1, 0);
vector<L>tree(size1);
void test1(int x)
{
    if (tree[x].l == 0)
    {
        D[x] = 1;
        return;
    }
    test1(tree[x].l);
    test1(tree[x].r);
    D[x] = (D[tree[x].l] + D[tree[x].r] + 3) % mod;
}
void test2(int x, long long sum)
{
    long long e;
    if (tree[x].l == 0)e = 1;
    else e = D[x];
    res[x] = (e + sum) % mod;
    long long next = (sum + D[x]) % mod;
    if (tree[x].l != 0)
    {
        test2(tree[x].l, next);
        test2(tree[x].r, next);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        fill(D.begin(), D.end(), 0);
        int n;
        cin >> n;
        for (int i = 0; i <= n; i++)tree[i] = { 0,0,0 };
        for (int i = 1; i <= n; i++)cin >> tree[i].l >> tree[i].r;
        test1(1);
        test2(1, 0);
        for (int i = 1; i <= n; i++)
        {
            cout << res[i];
            if (i <= n - 1)cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
