#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
void dfs(int a, int b, int x, int y, int k)
{
	if (k < 1)return;
	int len = 1 << (k - 1);
	//×óÉÏ½Ç
	if (x < a + len && y < b + len)
	{
		cout << a + len << ' ' << b + len <<' ' << '1' << '\n';
		dfs(a, b, x, y, k - 1);
		dfs(a, b + len, a + len - 1, b + len, k - 1);
		dfs(a + len, b, a + len, b + len - 1, k - 1);
		dfs(a + len, b + len, a + len, b + len, k - 1);

	}
	//ÓÒÉÏ½Ç
	else if (x < a + len&&y>= b + len)
	{
		cout << a + len << ' ' << b + len - 1 << ' ' << '2' << '\n';
		dfs(a, b, a + len - 1, b + len - 1, k - 1);
		dfs(a, b + len, x, y, k - 1);
		dfs(a + len, b, a + len, b + len - 1, k - 1);
		dfs(a + len, b + len, a + len, b + len, k - 1);
	}
	//×óÏÂ½Ç
	else if (x >= a + len&& y < b + len)
	{
		cout << a + len - 1 << ' ' << b + len << ' ' << '3' << '\n';
		dfs(a, b, a + len - 1, b + len - 1, k - 1);
		dfs(a, b + len, a + len - 1, b + len, k - 1);
		dfs(a + len, b, x, y, k - 1);
		dfs(a + len, b + len, a + len, b + len, k - 1);

	}
	//ÓÒÏÂ½Ç
	else
	{
		cout << a + len - 1 << ' ' << b + len - 1 << ' ' << '4' << '\n';
		dfs(a, b, a + len - 1, b + len - 1, k - 1);
		dfs(a, b + len, a + len - 1, b + len, k - 1);
		dfs(a + len, b, a + len, b + len - 1, k - 1);
		dfs(a + len, b + len, x, y, k - 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int k, x, y;
	cin >> k >> x >> y;
	dfs(1, 1, x, y, k);
	return 0;
}