#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int fa[N];
void start(int n)
{
    for (int i = 0; i <= n; i++)fa[i] = i;
}
int find(int x)
{
    if (fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
void un(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)fa[fx] = fy;
}
bool issameset(int x, int y)
{
    return fa[x] == fa[y];
}
int removeStones(vector<vector<int>>& stones)
{
    unordered_map<int, int>mp1, mp2;
    int n = stones.size();
    start(n);
    for(int i=0;i<n;i++)
    {
        int x = stones[i][0];
        int y = stones[i][1];
        if (!mp1.count(x))mp1[x] = i;
        else un(i, mp1[x]);
        if (!mp2.count(y))mp2[y] = i;
        else un(i, mp2[y]);
            
    }
    int ans = 0;
    for (int i = 0; i < n; i++)if (fa[i] == i)ans++;
    return n - ans;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    vector<vector<int>>arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i].push_back(x);
        arr[i].push_back(y);
    }
    cout << removeStones(arr);
    return 0;
}
