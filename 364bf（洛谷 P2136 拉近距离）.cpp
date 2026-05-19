#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u, v, w;
};
//const int N = 2e3 + 10;
vector<node>edg;
using ll = long long;
int n;
vector<ll>dist;
bool Bellman_ford(int x)
{

	dist.assign(n + 1, LLONG_MAX / 2);

	int p = n;
	dist[x] = 0;
	while (p--)
	{
		if (p > 1)
		{
			for (auto p : edg)
			{
				int u = p.u;
				int v = p.v;
				int w = p.w;
				if (dist[u] != LLONG_MAX / 2 && dist[u] + w < dist[v])dist[v] = dist[u] + w;

			}
		}
		else
		{
			for (auto p : edg)
			{
				int u = p.u;
				int v = p.v;
				int w = p.w;
				if (dist[u] != LLONG_MAX / 2 && dist[u] + w < dist[v])
				{
					return true;
				}

			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int m;
	cin >> n >> m;
	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edg.push_back({ u,v,-w });
	}
	if (Bellman_ford(1))cout << "Forever love";
	else
	{
		ll tmp1 = dist[n];
		Bellman_ford(n);
		ll tmp2 = dist[1];
		cout << min(tmp1, tmp2);
	}
	return 0;
}
