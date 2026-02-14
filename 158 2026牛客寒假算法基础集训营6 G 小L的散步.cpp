#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
bool test(vector<long long>& pre, long long p, long long l)
{
    auto it = upper_bound(pre.begin(), pre.end(), p);
    if (it != pre.end() && *it < p + l)return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n, m, l;
    cin >> n >> m >> l;
    vector<long long>pre(n);
    long long sum = 0LL;
    for (int i = 0; i < n; i++)
    {
        long long tem;
        cin >> tem;
        sum += tem;
        pre[i] = sum;
    }
    if (test(pre, 0, l))
    {
        cout << "YES";
        return 0;
    }
    long long pos = 0LL;
    bool judge = false;
    for (int i = 0; i < m; i++)
    {
        long long y;
        cin >> y;
        pos += y;
        if (test(pre, pos, l))judge = true;
    }
    if (judge)cout << "YES";
    else cout << "NO";
    return 0;
}
