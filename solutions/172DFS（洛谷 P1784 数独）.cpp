#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 15;
int path[N][N];
bool arr1[N][N], arr2[N][N], arr3[N][N][N];

bool dfs(int i, int j)
{
    if (j == 9)
    {
        i++;
        j = 0;
    }
    if (i == 9)return true;
    if(path[i][j])return dfs(i, j + 1);
    for (int x = 1; x <= 9; x++)
    {
        if (arr1[i][x] || arr2[j][x] || arr3[i / 3][j / 3][x])continue;
        arr1[i][x] = arr2[j][x] = arr3[i / 3][j / 3][x] = true;
        path[i][j] = x;
        if (dfs(i, j + 1))return true;
        arr1[i][x] = arr2[j][x] = arr3[i / 3][j / 3][x] = false;
        path[i][j] = 0;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int x;
            cin >> x;
            path[i][j] = x;
            if (x) arr1[i][x] = arr2[j][x] = arr3[i / 3][j / 3][x] = true;     
        }
    }
    dfs(0, 0);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)cout << path[i][j] << (j < 8 ? " " : "");
        cout << '\n';
    }
    return 0;
}
