#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long>arr(n);
        for (auto& num : arr)cin >> num;
        long long maxsum = max(k + arr[0], k + arr[n - 1]);
        for (int i = 0; i < n - 1; i++)maxsum = max(maxsum, arr[i] + arr[i + 1]);
        cout << maxsum << endl;
    }
    return 0;
}