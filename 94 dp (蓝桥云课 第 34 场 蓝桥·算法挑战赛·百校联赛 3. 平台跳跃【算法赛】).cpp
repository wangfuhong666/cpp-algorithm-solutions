#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> h(n + 1);
    for (int i = 1; i <= n; i++)cin >> h[i];
    if (n == 2)
    {
        cout << llabs(h[2] - h[1]);
        return 0;
    }
    ll a = 0, b = llabs(h[2] - h[1]), c;
    for (int i = 3; i <= n; i++)
    {
        c = min(b + llabs(h[i] - h[i - 1]), a + 3 * llabs(h[i] - h[i - 2]));
        a = b;
        b = c;
    }
    cout << c;
    return 0;
}