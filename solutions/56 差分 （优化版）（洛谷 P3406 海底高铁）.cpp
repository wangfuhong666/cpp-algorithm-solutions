#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<utility>
const int N = 1e5 + 10;
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>diff(N);
	int x, y;
	cin >> x;
	for (int i = 2; i <= m; i++)
	{
		cin >> y;
		if (x > y)diff[y]++, diff[x]--;
		else diff[x]++, diff[y]--;
		x = y;
	}
	for (int i = 1; i <= n; i++)diff[i] += diff[i - 1];
	long long sum = 0LL;
	for (int i = 1; i < n; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		sum+=min(diff[i] * a, diff[i] * b + c);
	}
	cout << sum;
	return 0;
}