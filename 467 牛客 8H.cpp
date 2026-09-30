#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const ll mod =998244353;
using i128 = __int128_t;
#define all(x) (x).begin(), (x).end()
void sol()
{
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    i128 sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (x == 1)
    {
        cout << (ll)(sum % mod) << '\n';
        return;
    }
    ll d = x - 1;
    vector<ll> price;
    i128 res = 0;  
    for (ll val : a)
    {
        res += val / x;
        ll tem = val % x;
        price.push_back(d - tem);
    }
    sort(all(price));
    i128 cnt = res;
    for (ll c : price)
    {
        if (res < c)
            break;

        res -= c;
        cnt++;
    }
    cnt += res / d;
    i128 ans = sum - cnt * d;
    cout << (ll)(ans % mod) << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)sol();
    return 0;
}
