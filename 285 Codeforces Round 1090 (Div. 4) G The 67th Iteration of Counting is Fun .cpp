#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const long long mod = 676767677;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) 
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n), brr(m, 0);
        for (int i = 0; i < n; i++) 
        {
            cin >> arr[i];
            brr[arr[i]]++;
        }
        vector<int> crr(m + 1, 0);
        for (int i = 0; i < m; i++)crr[i + 1] = crr[i] + brr[i];
        long long ans = 1;
        for (int i = 0; i < n; i++) 
        {
            if (arr[i] == 0) continue;
            int tem = arr[i];
            int cnt = INT_MAX;
            if (i > 0) cnt = min(cnt, arr[i - 1]);
            if (i < n - 1) cnt = min(cnt, arr[i + 1]);
            if (cnt >= tem) {
                ans = 0;
                break;
            }

            if (cnt < tem - 1)ans = (ans * brr[tem - 1]) % mod;
            else ans = (ans * crr[tem]) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}
