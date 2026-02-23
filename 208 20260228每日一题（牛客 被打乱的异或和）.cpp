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
        vector<int>arr(n, 0);
        for (auto& num : arr)cin >> num;
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            long long tem = 0 ^ arr[i];
            if (tem == arr[i])
            {
                res = arr[i];
                break;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
