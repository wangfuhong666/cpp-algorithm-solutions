#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
bool cmp(long long& a, long long& b)
{
	return a > b;
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<long long>>arrarr(n, vector<long long>(m));
	for (auto& row : arrarr)for (auto& num : row)cin >> num;
	long long cnt = -0x3f3f3f3f;
	vector<long long>col_sum(m, 0);
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			col_sum[j] += arrarr[i][j];
		}
	}
	for (int st1 = 0; st1 < (1 << n); st1++)
	{
		int tem1 = 0;
		long long sum = 0LL;
		vector<long long>tmp_col = col_sum;
		for (int i = 0; i < n; i++)
		{
			if ((st1 >> i) & 1)
			{
				tem1++;
				for (int j = 0; j < m; j++)
				{
					sum += arrarr[i][j];
					tmp_col[j] -= arrarr[i][j];
				}
			}
		}
		int tem2 = k - tem1;
		if (tem2 < 0)continue;
		sort(tmp_col.begin(), tmp_col.end(), cmp);
		long long sum1 = 0;
		int take = min(tem2, m);
		for (int j = 0; j < take; j++) {
			sum1 += tmp_col[j];
		}
		cnt = max(cnt, sum + sum1);
	}
	cout << cnt;
	return 0;
}