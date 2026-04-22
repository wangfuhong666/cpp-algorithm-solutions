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
        vector<int>arr(7);
        int maxn = INT_MIN;
        long long sum = 0;
        for (auto& num : arr)
        {
            cin >> num;
            maxn = max(maxn, num);
            sum += num;
        }
        cout << 2 * maxn - sum << '\n';
    }
    return 0;
}
