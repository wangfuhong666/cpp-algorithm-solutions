#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = +3e2 + 10;
int fa[N];
int setnum[N];
int sign[N];
void start(int n)
{
    for (int i = 0; i <= n; i++)
    {
        fa[i] = i;
        setnum[i] = 1;
        sign[i] = -1;
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
        fa[fx] = fy;
        setnum[fy] += setnum[fx];
    }
}
bool issameset(int x, int y)
{
    return find(x) == find(y);
}
class Solution
{
public:
    static int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial)
        {

        //
        unordered_map<int, int>mp;
        for (auto num : initial)mp[num]++;
        int n = graph.size();
        start(n);
        for (int i = 0; i < n; i++) {
            if (mp[i]) continue;
            for (int j = i + 1; j < n; j++) {
                if (!mp[j] && graph[i][j] == 1) un(i, j);
            }
        }
        int m = initial.size();
        for (int x : initial)
        {
            unordered_set<int> seenComponents;
            for (int j = 0; j < n; j++)
            {
                if (!mp[j] && graph[x][j] == 1)
                {
                    int root = find(j);
                    if (seenComponents.find(root) == seenComponents.end()) {
                        seenComponents.insert(root);
                        if (sign[root] == -1) sign[root] = x;
                        else if (sign[root] != x) sign[root] = -2;
                    }
                }
            }
        }
        vector<int> countSaved(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!mp[i] && fa[i] == i)
            {
                if (sign[i] >= 0)
                {
                    countSaved[sign[i]] += setnum[i];
                }
            }
        }



        sort(initial.begin(), initial.end());
        int res = initial[0], maxCnt = -1;
        for (int x : initial) {
            if (countSaved[x] > maxCnt) {
                maxCnt = countSaved[x];
                res = x;
            }
        }
        return res;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n, vector<int>(n));
    for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> adj[i][j];
    vector<int>point(m);
    for (int i = 0; i < m; i++)cin >> point[i];
    cout << Solution::minMalwareSpread(adj, point);
    return 0;
}
