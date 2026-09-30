#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int fa[2 * N];
struct node
{
    int x, y, e;
};
void start(int n)
{
    for (int i = 0; i <= n; i++)fa[i] = i;
}
int find(int x)
{
    if (fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
void un(int x, int y)
{
    fa[find(x)] = find(y);
}
bool is(int x, int y)
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
        int n;
        cin >> n;
        vector<node>arr(n + 1);
        vector<int>tmp;
        start(2 * n + 10);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].x >> arr[i].y >> arr[i].e;
            tmp.push_back(arr[i].x);
            tmp.push_back(arr[i].y);
        }
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        for (int i = 1; i <= n; i++)
        {
            arr[i].x = lower_bound(tmp.begin(), tmp.end(), arr[i].x) - tmp.begin() + 1;
            arr[i].y = lower_bound(tmp.begin(), tmp.end(), arr[i].y) - tmp.begin() + 1;
        }
        for (int i = 1; i <= n; i++)
        {
            int x = arr[i].x;
            int y = arr[i].y;
            int e = arr[i].e;
            if (e == 1)un(x, y);
        }
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            int x = arr[i].x;
            int y = arr[i].y;
            int e = arr[i].e;
            if (e == 0&&is(x,y))
            {
                ok=false;
                break;
            }
        }
        if (ok)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}