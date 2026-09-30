#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<bool>arr(2e7 + 100, false);
    int q;
    cin >> q;
    for (int i = 1; i <= (int)sqrt(2e7) + 1; i++)
    {
        for (int j = 1; j <= (int)sqrt(2e7) + 1; j++)
        {
            if (i * i + j * j <= 2e7)
            {
                arr[i * i + j * j] = true;
            }
        }
    }
    while (q--)
    {
        int n;
        cin >> n;
        if (arr[n])cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
