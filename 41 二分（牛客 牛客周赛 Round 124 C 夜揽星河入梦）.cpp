#define _CRT_SECURE_NO_WARNINGS
#include <iostream>   
#include <vector>   
#include <algorithm> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        long long n, m;
        cin >> n >> m;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        if (m == 2) {
            cout << "YES"<<endl;
            continue;
        }
        if (m > n + 1) {
            cout << "NO" << endl;
            continue;
        }

        bool ok = false;
        for (int i = 0; i < n; i++) {
            long long end = a[i] + m - 1;
            auto it = upper_bound(a.begin(), a.end(), end);
            long long cnt = it - a.begin() - i;
            if (cnt >= m - 1) 
            {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}