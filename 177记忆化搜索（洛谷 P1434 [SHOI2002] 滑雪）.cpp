#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int r, c;
const int N = 110;
int arr[N][N];
int memo[N][N];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int dfs(int x, int y)
{

	if (memo[x][y])return memo[x][y];
	int res = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || nx>r || ny<1 || ny>c)continue;
		if (arr[x][y] <= arr[nx][ny])continue;
		res = max(res, dfs(nx, ny)+1);
	}
	return memo[x][y] = res;

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c;
	for (int i = 1; i <= r; i++)for (int j = 1; j <= c; j++)cin >> arr[i][j];
	int ret = 1;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
		{
			ret = max(ret, dfs(i, j));
		}
	cout << ret;

	return 0;
}
