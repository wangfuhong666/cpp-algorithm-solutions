#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>dp(n + 1, 0);
	long long res = LLONG_MIN;
	for (int i = 1; i <= n; i++)
	{
		int x; 
		cin >> x;
		dp[i] = max(dp[i - 1] + x, x);
		res = max(res, 1LL*dp[i]);
	}
	cout << res;
	return 0;
}