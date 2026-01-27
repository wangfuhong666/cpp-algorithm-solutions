#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];

        int i = 0;
        while (i < n && p[i] == n - i) {
            i++;
        }

        if (i == n) {
            for (int j = 0; j < n; ++j) {
                cout << p[j] << " \n"[j == n - 1];
            }
            continue;
        }

 
        int target = n - i;
        int pos = find(p.begin(), p.end(), target) - p.begin();


        reverse(p.begin() + i, p.begin() + pos + 1);

        for (int j = 0; j < n; ++j) {
            cout << p[j] << " \n"[j == n - 1];
        }
    }
    return 0;
}
