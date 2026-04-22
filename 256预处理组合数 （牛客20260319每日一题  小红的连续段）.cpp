#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
using LL = long long;
LL C[N][N];
const LL mod = 1e9 + 7;
void start()
{
    for (int i = 0; i < N; i++)C[i][0] = 1;
    for (int i = 1; i < N; i++)for (int j = 1; j < N; j++)C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    start();
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= x + y; i++)
    {
        int n = i / 2;
        int m = (i + 1) / 2;
        cout << (C[x - 1][n - 1] * C[y - 1][m - 1] % mod + C[x - 1][m - 1] * C[y - 1][n - 1] % mod) % mod << '\n';
    }
    return 0;
}
