#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int>>arr(4, vector<int>(4, 0));
    unordered_map<int, int>mp;
    bool judge = true;
    long long cnt = 0LL;
    for (int i = 1; i <= 3; i++)
    {
        long long sum = 0LL;
        for (int j = 1; j <= 3; j++)
        {
            int x;
            cin >> x;
            if (mp[x] > 0)judge = false;
            arr[i][j] = x;
            mp[x]++;
            sum += x;
        }
        if (i == 1)cnt = sum;
        else
        {
            if (cnt != sum)
            {
                judge = false;
            }
        }
    }
    if (!judge)
    {
        cout << "No";
        return 0;
    }
    for (int i = 1; i <= 3; i++)
    {
        long long sum = 0LL;
        for (int j = 1; j <= 3; j++)
        {
            sum += arr[j][i];
        }
        if (sum != cnt)
        {
            cout << "No";
            return 0;
        }
    }
    long long sum1 = arr[1][1] + arr[3][3] + arr[2][2];
    long long sum2 = arr[3][1] + arr[1][3] + arr[2][2];
    if (sum1 == sum2 && sum1 == cnt)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}
