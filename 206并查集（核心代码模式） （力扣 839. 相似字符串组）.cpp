#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 3e2 + 10;
int fa[N];
int setnum;
void start(int n)
{
    for (int i = 0; i < n; i++)fa[i] = i;
    setnum = n;
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
        setnum--;
    }
}
bool issameset(int x, int y)
{
    return find(x) == find(y);
}
bool check(string s1, string s2)
{
    if (s1.size() != s2.size())return false;
    int tem = 0;
    for (int i = 0; i < s1.size(); i++)if (s1[i] != s2[i])tem++;
    if (tem == 0 || tem == 2)return true;
    return false;
}
int numSimilarGroups(vector<string>& strs)
{
    int n = strs.size();
    start(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (check(strs[i], strs[j])&&!issameset(i,j))un(i, j);
        }
    }
    return setnum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string>arr(n);
    for (auto& e : arr)cin >> e;
    cout << numSimilarGroups(arr);
    return 0;
}
