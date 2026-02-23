#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
struct mat
{
    long long n, m;
    vector<vector<long long>>c;
    mat(int n,int m):n(n),m(m),c(n,vector<long long>(m,0)){}

};
mat operator*(mat a, mat b)
{
    int n1 = a.n;
    int m1 = a.m;
    int n2 = b.n;
    int m2 = b.m;
    mat res(n1, m2);
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            for (int k = 0; k < m1; k++)
            {
                res.c[i][j] = (res.c[i][j] + a.c[i][k] * b.c[k][j] % mod) % mod;

            }
        }
    }
    return res;
}
mat matqpow(mat a, long long b)
{
    mat res(a.n, a.m);
    for (int i = 0; i < a.n; i++)res.c[i][i] = 1;
    while (b)
    {
        if (b & 1)res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
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
        if (n <= 3)
        {
            cout << 1 << '\n';
            continue;
        }   
        mat cnt(3, 3);
        cnt.c =
        {
            {1, 0, 1},
            {1, 0, 0},
            {0, 1, 0}
        };
        mat res = matqpow(cnt, n - 3);
        vector<vector<long long>>ans = res.c;
        cout << (ans[0][0] + ans[0][1] + ans[0][2]) % mod << '\n';
        
    }
    return 0;
}
