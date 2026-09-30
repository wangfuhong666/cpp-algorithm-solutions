#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n; 
	cin >> n;
	vector<long long>f(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		f[i] = f[i - 1] + x;
	}
	long long ret = -0x3f3f3f;
	long long fmin = 0;
	for (int i = 1; i <= n; i++)
	{
		ret = max(ret, f[i] - fmin);
		fmin = min(fmin, f[i]);
	}
	cout << ret;
	return 0;
}