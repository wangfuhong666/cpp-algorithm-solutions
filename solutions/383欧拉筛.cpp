#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ump unordered_map
#define ms multiset
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
typedef __int128 i128;
template <typename T>
inline void read(T &x)
{
    x = 0;
    int f = 1;
    char ch;
    while ((ch = getchar()) > '9' || ch < '0')
        if (ch == '-')
            f = -1;
    while (ch >= '0' && ch <= '9')
        x = x * 10 + (ch ^ '0'), ch = getchar();
    x *= f;
}
const int N = 1e6 + 10;
vi prime;
vb isprime(N, true);
void getprime(int n)
{
    isprime[0] = isprime[1] = false;
    rep(i, 2, n + 1)
    {
        if (isprime[i]) prime.pb(i);
        for (int j = 0; j < sz(prime) && 1LL*i * prime[j] <= n; j++)
        {
            isprime[i * prime[j]] = false;
            if(i%prime[j]==0)break;
        }
    }
}
void sol()
{
    int n;
    read(n);
    getprime(n);

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