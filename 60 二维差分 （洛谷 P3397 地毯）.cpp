#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<long long>>arr(n + 1, vector<long long>(n + 1));
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)cin >> arr[i][j];
	vector<vector<long long>>diff(n + 2, vector<long long>(n + 2)), difftem(n + 2, vector<long long>(n + 2));
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)difftem[i][j] = arr[i][j] - arr[i][j - 1];
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)diff[i][j] = difftem[i][j] - difftem[i - 1][j];
	while (m--)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2 ;
		diff[y1][x1] += 1;
		diff[y2 + 1][x1] -= 1;
		diff[y1][x2 + 1] -= 1;
		diff[y2 + 1][x2 + 1] +=1;
	}
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)arr[i][j] = diff[i][j];
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)arr[i][j] += arr[i][j - 1];
	for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)arr[i][j] += arr[i - 1][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << arr[i][j];
			if (j < n)cout << ' ';
		}
		cout << endl;
	}
	return 0;
}