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
        vector<long long> arra(n);
        for (int i = 0; i < n; i++) cin >> arra[i];
        vector<long long> arrm(n);
        arrm[n - 1] = arra[n - 1];
        for (int i = n - 2; i >= 0; i--) arrm[i] = min(arra[i], arrm[i + 1]);
        long long res = 0;
        for (int i = 0; i < n; i++)res += (arra[i] - arrm[i]);
        map<long long, int> mp;
        for (int i = 0; i < n; i++) if (!mp.count(arrm[i]))mp[arrm[i]] = i;
        int cnt = 0;
        for (int i = 0; i < n; i++) if (arra[i] == arrm[i]) cnt = max(cnt, i - mp[arrm[i]]);
        cout << res + cnt << "\n";
    }
    return 0;
}
