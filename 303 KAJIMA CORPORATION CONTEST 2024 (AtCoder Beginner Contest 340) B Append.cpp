#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int q;
    cin >> q;
    vector<int>arr;
    while (q--)
    {
        int op; cin >> op;
        if (op == 1)
        {
            int k; cin >> k;
            arr.push_back(k);
        }
        else
        {
            int k; cin >> k;
            cout << arr[(int)arr.size() - k] << '\n';
        }
    }

    return 0;
}
