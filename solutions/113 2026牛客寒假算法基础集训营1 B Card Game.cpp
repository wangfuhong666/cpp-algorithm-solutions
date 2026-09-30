#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
const long long mod = 998244353;
const int nums = 2e5 + 5;
void start(vector<long long>& pre)
{
    pre[0] = 1;
    for (int i = 1; i < pre.size(); i++)pre[i] = (pre[i - 1] * i) % mod;
}

int main()
{
    vector<long long>pre(nums);
    start(pre);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<long long>a(n), b(n);
        for (auto& num : a)cin >> num;
        for (auto& num : b)cin >> num;
        long long minb = *min_element(b.begin(), b.end());
        long long count = 0LL;
        for (auto num : a)if (num > minb)count++;
        if (count == 0 || count == n)cout << pre[n] << endl;
        else cout << (pre[count] * pre[n - count]) % mod << endl;
    }
    return 0;
}