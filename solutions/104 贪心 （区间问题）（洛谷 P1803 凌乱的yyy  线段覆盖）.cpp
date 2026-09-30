#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
using PII = pair<int, int>;
bool cmp(PII a, PII b)
{
	if (a.first != b.first)return a.first < b.first;
	return a.second < b.second;
}
int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	vector<PII>arr(n);
	for (auto& num : arr)cin >> num.first >> num.second;
	sort(arr.begin(), arr.end(), cmp);
	
	int l = arr[0].first, r = arr[0].second;
	long long cnt = 1LL;
	for (int i = 1; i < n; i++)
	{
		if (r <= arr[i].first)
		{
			cnt++;
			l = arr[i].first;
			r = arr[i].second;
		}
		if (r>arr[i].first && r >= arr[i].second)
		{
			
			l = arr[i].first;
			r = arr[i].second;
		}
	}
	cout << cnt;
	return 0;
}