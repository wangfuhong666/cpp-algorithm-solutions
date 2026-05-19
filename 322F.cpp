#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

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
        vector<long long> arra(n + 1);
        vector<long long> arrb(n + 1);
        long long sum = 0;
        long long tem = 0;
        for (int i = 1; i <= n; i++) 
        {
            cin >> arra[i];
            arrb[i] = arra[i];
            tem += (long long)i * arra[i];
        }
        sort(arrb.begin() + 1, arrb.end());
        long long ret = 0;
        map<long long, int> mp;
        for (int i = 1; i <= n; i++) 
        {
            ret += (long long)i * arrb[i];
            if (!mp.count(arrb[i])) mp[arrb[i]] = i;
        }
        long long res = 0;
        for (int i = 1; i <= n; i++)  res = max(res, (long long)i - mp[arra[i]]);
        cout << ret - tem + res << "\n";
    }
    return 0;
}
