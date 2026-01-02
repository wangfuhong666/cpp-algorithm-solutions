//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	int n, m,q;
//	cin >> n >> m>>q;
//	vector<vector<long long>>arr(n + 1, vector<long long>(m + 1));
//	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)cin >> arr[i][j];
//	vector<vector<long long>>diff(n + 2, vector<long long>(m + 2)), difftem(n + 2, vector<long long>(m + 2));
//	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)difftem[i][j] = arr[i][j] - arr[i][j - 1];
//	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)diff[i][j] = difftem[i][j] - difftem[i - 1][j];
//	while (q--)
//	{
//		int x1, y1, x2, y2, k;
//		cin >> y1 >> x1 >> y2 >> x2 >> k;
//		diff[y1][x1] += k;
//		diff[y2+1][x1] -= k;
//		diff[y1][x2+1] -= k;
//		diff[y2+1][x2+1] += k;
//	}
//	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)arr[i][j] = diff[i][j];
//	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)arr[i][j] += arr[i][j-1];
//	for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)arr[i][j] += arr[i-1][j];
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++)
//		{
//			cout << arr[i][j]; 
//			if (j < m)cout << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}