#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
//节点的值
vector<int>VAL(N, 0);
//标记节点是否存在
vector<bool>sign(N, false);
//邻接表
vector<vector<int>>adj(N);
//父节点信息
vector<int>P(N, 0);
//实际节点数
int n;
int getroot()
{
    for (int i = 0; i < N; i++)if (sign[i] && P[i] == 0)return i;
    return 1;
}
void preorder(int root)
{
    if (root == 0 || sign[root] == false)return;
    cout << VAL[root] << ' ';
    for (auto u : adj[root])preorder(u);
}
void postorder(int root)
{
    if (root == 0 || sign[root] == false)return;
    for (auto u : adj[root])postorder(u);
    cout << VAL[root] << ' ';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int idx, val, nums;
        cin >> idx >> val >> nums;
        VAL[idx] = val;
        sign[idx] = true;
        if (nums == 0)continue;
        for (int k = 0; k < nums; k++)
        {
            int x;
            cin >> x;
            adj[idx].push_back(x);
            P[x] = idx;
            sign[idx] = true;
        }
    }
    for (int i = 0; i < N; ++i)if (sign[i]) sort(adj[i].begin(), adj[i].end());      
    int root = getroot();
    preorder(root);
    cout << '\n';
    postorder(root);
    return 0;
}
