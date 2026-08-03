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
        long long k;
        cin >> n >> k;
        vector<int> arr(n);
        for (auto& num : arr) cin >> num;

        sort(arr.begin(), arr.end(), greater<int>());

        long long sum = 0;
        long long ans = 0;

        for (int i = 1; i <= n; i++)
        {
            long long cur = sum;
            sum += arr[i - 1];

            long long tem = (long long)(n - i) * k + i;

            if (tem <= sum)
            {
                ans = max(cur + 1, tem);
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}