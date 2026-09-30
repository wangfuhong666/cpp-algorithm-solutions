#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

#define all(x) (x).begin(), (x).end()

bool check(vector<ll>& pre, ll a, int mid, int r)
{
    return pre[r - 1] - pre[mid - 1] > a;
}

void sol()
{
    int n;
    cin >> n;

    vector<ll> a(n + 1, 0), pre(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a.begin() + 1, a.end());

    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];

    vector<int> ret(n + 1, -1);

    for(int i = 3; i <= n; i++)
    {
        int l = 1;
        int rr = i - 1;
        int ans = -1;

        while(l <= rr)
        {
            int mid = l + (rr - l) / 2;

            if(check(pre, a[i], mid, i))
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                rr = mid - 1;
            }
        }

        if(ans != -1)
        {
            int k = i - ans + 1;

            ret[k] = max(ret[k], i);
        }
    }

    for(int k = 1; k <= n; k++)
        ret[k] = max(ret[k], ret[k - 1]);

    for(int k = 1; k <= n; k++)
    {
        if(k < 3 || ret[k] == -1 || ret[k] < k)
        {
            cout << 0;
        }
        else
        {
            int R = ret[k];
            int L = R - k + 1;

            cout << pre[R] - pre[L - 1];
        }

        cout << " \n"[k == n];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--)
        sol();

    return 0;
}