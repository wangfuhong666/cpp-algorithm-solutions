#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, m,q;
	cin >> n >> m>>q;
	vector<vector<int>>arr(n, vector<int>(m));
	vector<vector<long long>>sum(n+1, vector<long long>(m+1));
	for (auto& row : arr)for (auto& num : row)cin >> num;
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)sum[i][j] = arr[i - 1][j - 1];
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)sum[i][j] += sum[i - 1][j];
	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)sum[i][j] += sum[i][j-1];
	while (q--)
	{
		int x1, x2, y1, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] + sum[y1 - 1][x1 - 1]<<endl;
	}


	return 0;
}