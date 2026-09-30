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
        vector<long long> arr(n);
        for (auto& num : arr) cin >> num;
        sort(arr.begin(), arr.end());
        long long sum = 0;
        int i = 0;
        while (i < n - 1 && arr[i] + sum <= 0)sum += arr[i++] + sum;

        long long ans = 0;
        for (int j = i; j < n; j++) ans += arr[j] + sum;
        cout << ans << "\n";
    }
    return 0;
}。