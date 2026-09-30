#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n;
string path;
void dfs(int pos)
{
    //处理递归出口
    if (pos > n)
    {
        cout << path << '\n';
        return;
    }
    //不选的情况
    path += 'N';
    dfs(pos + 1);
    //回溯之前的状态
    path.pop_back();
    //选的情况
    path += 'Y';
    dfs(pos + 1);
    //回溯之前的状态
    path.pop_back();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    dfs(1);
    return 0;
}
