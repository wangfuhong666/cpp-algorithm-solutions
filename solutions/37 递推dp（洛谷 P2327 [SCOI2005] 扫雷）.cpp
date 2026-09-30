#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool DP(int n,int s, vector<int>&dp, vector<int>&num)
{
	dp[1] = s;
	dp[2] = num[1] - dp[1];
	if (dp[2] != 0 && dp[2] != 1)return false;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = num[i - 1] - dp[i - 2] - dp[i - 1];
		if (dp[i] != 0 && dp[i] != 1)return false;
	}
	if (num[n] != dp[n - 1] + dp[n])return false;
	return true;


}
int main()
{
	
	int n,count=0;
	cin >> n;
	vector<int>dp(n + 1);
	vector<int>num(n + 1);
	for (int i = 1; i <= n; i++)cin >> num[i];
	if (n == 1)
	{
		if (num[1] == 0 || num[1] == 1)cout << 1;
		else cout << 0;
	}
	else
	{
		if (DP(n, 1, dp, num))count++;
		if (DP(n, 0, dp, num))count++;
		cout << count;
	}


	return 0;
}