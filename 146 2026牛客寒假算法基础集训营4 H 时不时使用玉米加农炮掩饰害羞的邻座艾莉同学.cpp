#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, q;
	cin >> n >> m >> q;
	vector<int>dx{ 0, 0, 0, 0, 0, 1, 1, 1, -1, -1, -1, 2, -2 };
	vector<int>dy{ 0, 1, 2, -1, -2, 0, 1, -1, 0, 1, -1, 0, 0 };
	vector<vector<long long>>arr1(n+1, vector<long long>(m+1));
	vector<vector<long long>>arr2(n+1, vector<long long>(m+1));
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)cin >> arr1[i][j];
	long long maxsum=-1LL;
	long long maxx = 1LL, maxy = 1LL;
	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= m; j++)
		{
			if (arr1[i][j] == 0)continue;
			for (int k = 0; k < 13; k++)
			{
				int idx = i + dx[k], idy = j + dy[k];
				if (idx >= 1 && idx <= n && idy >= 1 && idy <= m)arr2[idx][idy] += arr1[i][j];
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= m; j++)
		{
			if (arr2[i][j] > maxsum)
			{
				maxsum = arr2[i][j];
				maxx = i;
				maxy = j;
			}
		}
	}
	while (q--)
	{
		int x, y;
		long long z;
		cin >> x >> y >> z;
		for (int k = 0; k < 13; k++)
		{
			int idx = x + dx[k],idy = y + dy[k];
			if(idx >= 1 && idx <= n && idy >= 1 && idy <= m)
			{
				arr2[idx][idy] += z;
				if (arr2[idx][idy] > maxsum)
				{
					maxsum = arr2[idx][idy];
					maxx = idx;
					maxy = idy;
				}

			}
		}
	}
	cout << maxx << ' ' << maxy;
	return 0;
}