#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int maxsize = 50;
//棋盘大小
int n;
//记录解法的个数
int res;
//记录皇后的位置
vector<int>path;
//标记列 j
vector<bool>mp1(maxsize);
//标记对角线1 i+j
vector<bool>mp2(maxsize);
//标记对角线2 i-j+n
vector<bool>mp3(maxsize);
void dfs(int begin)
{
    if (begin == n + 1)
    {
        res++;
        if (res <= 3)
        {
            for (int i = 0; i < path.size(); i++)cout << path[i] << (i < path.size() - 1 ? ' ' :'\n');
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp1[i] || mp2[begin + i] || mp3[begin - i + n])continue;
        path.push_back(i);
        mp1[i] = true;
        mp2[begin + i] = true;
        mp3[begin - i + n] = true;
        dfs(begin + 1);
        path.pop_back();
        mp1[i] = false;
        mp2[begin + i] = false;
        mp3[begin - i + n] = false;

    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //使用全局的东西一定要清空，养成习惯
    res = 0;
    path.clear();
    fill(mp1.begin(), mp1.end(), false);
    fill(mp2.begin(), mp2.end(), false);
    fill(mp3.begin(), mp3.end(), false);
    //处理输入
    cin >> n;
    //开始搜索
    dfs(1);
    //输出答案
    cout << res;
    return 0;
}
