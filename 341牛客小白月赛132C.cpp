#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<ULL>arr;
    for (int x = 0; x < 63; x++)for (int y = 0; y < 63; y++)arr.push_back((1ULL << x) + (1ULL << y));
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    int T;
    cin >> T;
    while (T--)
    {
        ULL l, r;
        cin >> l >> r;
        auto it1 = lower_bound(arr.begin(), arr.end(), l);
        auto it2 = upper_bound(arr.begin(), arr.end(), r);
        cout << it2 - it1 << '\n';
    }
    return 0;
}
