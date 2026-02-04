#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	map<long long, long long>mp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		long long l, r;
		cin >> l >> r;
		mp[l]++; mp[r]--;
	}
	long long sum = 0LL, cnt = 0LL, pos = -1LL;
	for (auto it = mp.begin(); it != mp.end(); it++)
	{
		long long tem1 = it->first;
		long long tem2 = it->second;
		if (cnt > 0 && pos != -1)sum += tem1 - pos;
		cnt += tem2;
		pos = tem1;
	}
	cout << sum;
	return 0;
}