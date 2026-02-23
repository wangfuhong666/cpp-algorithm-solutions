#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 3e4 + 10;
vector<int>val;
//并查集
int fa[N];
//存储代表集合的最大值
int maxval[N];
//存储代表集合的最大值数量
int maxnum[N];
void start(int n)
{
    for (int i = 0; i < n; i++)
    {
        fa[i] = i;
        maxval[i] = val[i];
        maxnum[i] = 1;
    }
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
    if (fx != fy)
    {
        if (maxval[fx] == maxval[fy])
        {
            fa[fx] = fy;
            maxnum[fy] += maxnum[fx];
        }
        else
        {
            if (maxval[fx] < maxval[fy]) fa[fx] = fy;
            else fa[fy] = fx;
        }
    }
}
bool issameset(int x, int y)
{
    return find(x) == find(y);
}

bool cmp(vector<int>& a, vector<int>& b)
{
    return max(val[a[0]], val[a[1]]) < max(val[b[0]], val[b[1]]);
}
class Solution
{
public:
    static int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges)
    {
        val = vals;
        sort(edges.begin(), edges.end(), cmp);
        start(vals.size());
        int n = edges.size();
        long long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int fa = find(edges[i][0]);
            int fb = find(edges[i][1]);
            if (maxval[fa] == maxval[fb])cnt += maxnum[fa] * maxnum[fb];
            un(fa, fb);
        }
        return cnt + vals.size();
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>vals(n);
    for (auto& num : vals)cin >> num;
    vector<vector<int>>edges(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[i].emplace_back(x, y);
    }
    cout << Solution::numberOfGoodPaths(vals, edges);
    return 0;
}
