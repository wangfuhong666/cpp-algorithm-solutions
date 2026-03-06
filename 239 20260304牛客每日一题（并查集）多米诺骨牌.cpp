#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using PLL = pair<long long, long long>;
int fa[N];
int setnum[N];
void start(int n)
{
    for (int i = 0; i < n; i++)
    {
        fa[i] = i;
        setnum[i] = 1;
    }
}
int find(int x)
{
    if (fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
void un(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        fa[fx] = fy;
        setnum[fy] += setnum[fx];
    }
}
bool issameset(int x, int y)
{
    return find(x) == find(y);
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
        int n, m;
        cin >> n >> m;
        start(n);
        vector<PLL>arr;
        vector<long long>glad(n);
        for (int i = 0; i < n; i++)cin >> glad[i];
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            arr.emplace_back(x, glad[i] + x);
        }
        sort(arr.begin(), arr.end());
        if (n == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        long long last = arr[0].second;
        int l = 0;
        for (int i = 1; i < n; i++)
        {
            if (last >= arr[i].first)
            {
                un(l, i);
                last = max(last, arr[i].second);
            }
            else
            {
                l = i;
                last = arr[i].second;
            }
        }
        vector<int>ans;
        for (int i = 0; i < n; i++)if (fa[i] == i)ans.push_back(setnum[i]);
        sort(ans.begin(), ans.end(), greater<int>());
        m = min((int)ans.size(), m);
        long long cnt = 0LL;
        for (int i = 0; i < m; i++)cnt += ans[i];
        cout << cnt << '\n';

    }
    return 0;
}
