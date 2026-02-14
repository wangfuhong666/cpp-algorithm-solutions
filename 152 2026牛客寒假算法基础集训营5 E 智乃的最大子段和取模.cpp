#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    long long p;
    cin >> n >> p;
    vector<long long>arr(n);
    for (int i = 0; i < n; i++)cin >> arr[i];
    set<pair<long long, int>>s;
    s.insert({ 0,-1 });
    long long cur = 0LL,maxsum = -1LL;
    int cntl = -1, cntr = -1;
    for (int i = 0; i < n; i++)
    {
        cur = (cur + arr[i]) % p;
        auto itmin = s.begin();
        long long sum1 = (cur - itmin->first + p) % p;
        if (sum1 > maxsum)
        {
            maxsum = sum1;
            cntl = itmin->second + 1;
            cntr = i;
        }
        auto itmax = s.upper_bound({ cur,n + 1 });
        if (itmax != s.end())
        {
            long long sum2 = (cur - itmax->first + p) % p;
            if (sum2 > maxsum)
            {
                maxsum = sum2;
                cntl = itmax->second + 1;
                cntr = i;
            }
        }
        s.insert({ cur,i });
    }
    cout << cntl << ' ' << cntr << ' ' << maxsum;
    return 0;
}
