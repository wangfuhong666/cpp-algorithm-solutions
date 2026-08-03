#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template <typename T>
inline void read(T &x)
{
    x = 0;
    int flag = 1;
    int ch = getchar_unlocked();

    while (ch > '9' || ch < '0')
    {
        if (ch == '-') flag = -1;
        ch = getchar_unlocked();
    }

    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar_unlocked();
    }

    x *= flag;
}

template <typename T>
inline void print(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }

    if (x > 9) print(x / 10);

    putchar(x % 10 + '0');
}
void sol()
{
    ll x=0;
    int n;
    read(n);
    while(n--)
    {
        int y;
        read(y);
        x+=y;
    }
    print(x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--)sol();
    return 0;
}
