#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n, q, s;
	cin >> n >> q >> s;
	vector<long long>arr(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		long long x;
		cin >> x;
		arr[i] = arr[i - 1] + x;
	}
	while (q--)
	{
		long long x, y;
		cin >> x >> y;
		cout << arr[x - 1] + y - 1 + s << '\n';
	}
	return 0;
}