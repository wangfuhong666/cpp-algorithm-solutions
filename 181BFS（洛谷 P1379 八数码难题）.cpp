#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
struct node
{
    string s;
    int pos0;
    int pos;
}f;
string aim = "123804765";

unordered_map<string, int>mp;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
void bfs()
{
    queue<node>q;
    q.push(f);
    mp[f.s] = 1;
    while (!q.empty())
    {
        node p = q.front();
        q.pop();
        if (p.s == aim)
        {
            cout << p.pos;
            return;
        }
        int wei0 = p.pos0;
        int x = wei0 / 3;
        int y = wei0 % 3;       
        int postem = p.pos;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx>2 || ny < 0 || ny>2)continue;
            string tmp = p.s;
            int k = nx * 3 + ny;
            swap(tmp[wei0], tmp[k]);
            if (mp.count(tmp))continue;
            mp[tmp] = 1;
            q.push({ tmp, k, postem + 1 });
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string tem;
    for (int i = 0; i < 9; i++)
    {
        char x;
        cin >> x;
        tem += x;
        if (x == '0')f.pos0 = i;
    }
    f.s = tem;
    f.pos = 0;
    bfs();
    return 0;
}
