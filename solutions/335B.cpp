#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using LD = long double;
int arr[3][3] = { 0 };
vector<bool>vis(3, false);
int dfs(int idx)
{
    if (idx == 3) return 1;

    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        if (vis[i]) continue;
        vis[i] = true;
        sum += arr[idx][i] * dfs(idx + 1);
        vis[i] = false;
    }
    return sum;
} 
int main()
{
    for (int i = 0; i < 3; i++)
    {
        int n = 6;
        while (n--)
        {
            int x;
            cin >> x;
            if (x >= 4 && x <= 6)arr[i][x - 4]++;
        }
    }
    int sum = dfs(0);
    LD res = sum / 216.0;
    printf("%10Lf", res);
    return 0;
}
