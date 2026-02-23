#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
using PII = pair<int, int>;
int x, y;
vector<bool>memo(N, false);

void bfs()
{
    queue<PII>q;
    q.emplace(x, 0);
    memo[x] = true;
    while (!q.empty())
    {
        PII p = q.front(); 
        q.pop();
        if (p.first == y)
        {
            cout << p.second << '\n';
            return;
        }
        int tem = p.first;
        int pos = p.second;
        if (tem + 1 < N && !memo[tem + 1])
        {
            q.emplace(tem + 1, pos + 1);
            memo[tem + 1] = true;
        }
        if (tem - 1  >0 && !memo[tem - 1])
        {
            q.emplace(tem - 1, pos + 1);
            memo[tem - 1] = true;
        }
        if (tem *2 < N && !memo[tem * 2])
        {
            q.emplace(tem * 2, pos + 1);
            memo[tem * 2] = true;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        fill(memo.begin(), memo.end(), false);
        cin >> x >> y;
        bfs();
    }
    return 0;
}
