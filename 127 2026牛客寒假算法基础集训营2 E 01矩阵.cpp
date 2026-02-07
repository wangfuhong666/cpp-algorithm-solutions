#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
bool judge(int n, int x, int y)
{
    if (x > n || x<0 || y>n || y < 0)return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << '0' << endl;
        return 0;
    }
    vector<vector<int>>arr(n + 1, vector<int>(n + 1, 0));
    for (int i = 2; judge(n, i, 0); i += 2)
    {
        for (int j = i; judge(n, i, j); j++)
        {
            arr[i][j] = 1;
            arr[j][i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)cout << arr[i][j];
        cout << '\n';

    }
    return 0;
}