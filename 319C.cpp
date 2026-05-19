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
        vector<int>arr0, arr2, arr3, arr6;
        while (n--)
        {
            int x;
            cin >> x;
            if (x % 2 == 0 && x % 3 == 0)arr6.push_back(x);
            else if (x % 2 == 0)arr2.push_back(x);
            else if (x % 3 == 0)arr3.push_back(x);
            else arr0.push_back(x);
        }
        for (auto e : arr2)cout << e << ' ';
        for (auto e : arr0)cout << e << ' ';
        for (auto e : arr3)cout << e << ' ';
        for (auto e : arr6)cout << e << ' ';
        cout << '\n';
    }
    return 0;
}
