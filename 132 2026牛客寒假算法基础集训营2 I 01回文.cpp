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
        int n, m;
        cin >> n >> m;
        long long cnt0 = 0LL, cnt1 = 0LL;
        vector<string>arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            for (int j = 0; j < arr[i].size(); j++)
            {
                if (arr[i][j] == '1')cnt1++;
                else cnt0++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                if (arr[i][j] == '0')
                {
                    if (cnt0 > 1)cout << 'Y';
                    else cout << 'N';
                }
                else
                {
                    if (cnt1 > 1)cout << 'Y';
                    else cout << 'N';
                }
            }
            cout << '\n';
        }
    }
    return 0;
}