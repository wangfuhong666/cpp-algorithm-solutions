#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
using ll = long long;
vector<ll>tim(N, 0);
vector<int>adj[N];
vector<ll>dp(N, 0);
vector<int>du(N, 0);
int n;
ll topsort()
{
	cin >> n;
	int m = n;
	while (m--)
	{
		int id, len;
		cin >> id >> len;
		tim[id] = len;
		while (1)
		{
			int y;
			cin >> y;
			if (!y)break;
			adj[y].push_back(id);
			du[id]++;
		}
	}
	queue<int>q;
	for (int i = 1; i <= n; i++)if (!du[i])q.push(i);
	ll res = 0;
	while (!q.empty())
	{
		int c = q.front();
		q.pop();
		dp[c] += tim[c];
		res = max(res, dp[c]);
		for (auto b : adj[c])
		{
			dp[b] = max(dp[b], dp[c]);
			du[b]--;
			if (!du[b])q.push(b);
		}
	}

	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << topsort();
	return 0;
}
