#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int concatenatedBinary(int n)
{
	vector<int>f;
	for (int i = n; i >= 1; i--)
	{
		int x = i;
		while (x)
		{
			f.push_back(x & 1);
			x >>= 1;
		}
	}
	long long res = 0LL;
	long long powb = 1;
	for (auto e : f)
	{
		res += e * powb;
		res %= mod;
		powb <<= 1;
		powb %= mod;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	cout << concatenatedBinary(n);
	return 0;
}
