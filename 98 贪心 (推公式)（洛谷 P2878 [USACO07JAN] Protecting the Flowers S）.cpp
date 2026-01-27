#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
using PII = pair<int, int >;
bool cmp(PII a,PII b)
{

	return 1LL * a.first * b.second < 1LL * b.first * a.second;
}
int main()
{
	int n;
	cin >> n;
	long long sum = 0LL;
	vector<PII>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
		sum += arr[i].second;
	}
	sort(arr.begin(), arr.end(),cmp);
	long long res = 0LL;
	for (int i = 0; i < n; i++)
	{
		sum -= arr[i].second;
		res += sum * arr[i].first*2;
	}
	cout << res;
	return 0;
}
