#include<bits/stdc++.h>

using namespace std;
const long long mod = 998244353;
vector<string>num
{
    "1110111",//0
    "0010010",//1
    "1011101",//2
    "1011011",//3
    "0111010",//4
    "1101011",//5
    "1101111",//6
    "1010010",//7
    "1111111",//8
    "1111011"//9
};
long long qpow(long long a, long long b, long long p)
{
    a %= p;
    long long res = 1LL;
    while (b != 0)
    {
        if (b & 1)res = res * a % p;
        a = a * a % p;
        b >>= 1;

    }
    return res;
}
long long divimod(long long a, long long b, long long p)
{
    long long res = qpow(b, p - 2, p);
    return (a % p * res % p) % p;
}
long long test(int a, vector<long long >& p)
{
    if (a == 0)return qpow(p[0], 4, mod);
    int len = to_string(a).size();
    string s = "";
    s.append(4 - len, '0');
    s += to_string(a);
    long long res = 1LL;
    for (int i = 0; i < 4; i++)
    {
        int tem = s[i] - '0';
        res *= p[tem];
        res %= mod;
    }
    return res;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int C;
        cin >> C;
        vector<int>p1(7);
        for (int i = 0; i < 7; i++)cin >> p1[i];
        vector<long long >p(10, 1);
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                if (num[i][j] - '0')p[i] = divimod(p[i] * p1[j], 100, mod);
                else p[i] = divimod(p[i] * (100 - p1[j]), 100, mod);
            }

        }
        long long cnt = 0LL;
        for (int i = 0; i <= C; i++)
        {
            int j = C - i;
            cnt += (test(i, p) * test(j, p)) % mod;
            cnt %= mod;
        }
        cout << cnt << endl;

    }
    return 0;
}