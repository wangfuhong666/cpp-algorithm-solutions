#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
using PLL = pair<long long, long long>;
bool cmp(PLL c1, PLL c2)
{
	return c2.first - c1.second < c1.first - c2.second;
}
int main()
{
	int n;
	cin >> n;
	vector<PLL>arr(n);
	long long weight = 0LL;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		weight += arr[i].first;
	}
	sort(arr.begin(), arr.end(), cmp);
	long long cnt = LLONG_MIN;
	for (int i = 0; i < n; i++)
	{
		weight -= arr[i].first;
		cnt = max(cnt, weight  - arr[i].second);
		
	}
	cout << cnt;
	
	return 0;
}