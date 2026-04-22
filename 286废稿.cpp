#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) 
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
       int ans = INT_MIN;
        for (int i = 0; i + 1 < n; i++) 
        {
            int maxn = max(arr[i], arr[i + 1]);
            int tem;
            if (arr[i] != 0 && arr[i + 1] != 0) {
                tem = 0;
            }
            else if (arr[i] != 1 && arr[i + 1] != 1) {
                tem = 1;
            }
            else {
                tem = 2;
            }
            ans = max(ans, maxn - tem);
        }

        cout << ans << "\n";
    }
}