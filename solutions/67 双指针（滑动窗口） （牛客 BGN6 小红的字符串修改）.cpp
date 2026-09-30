#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();
	int l = 0, r = n - 1;
	long long minsum = 0x3f3f3f3f;
	while (r < m)
	{
		long long sum = 0LL;
		for (int i = 0; i < n; i++)sum += min(abs(t[l + i] - s[i]), abs(26 - abs(t[l + i] - s[i])));
		minsum = min(minsum, sum);
		l++;
		r++;
		

	}
	cout << minsum;
	return 0;
}
