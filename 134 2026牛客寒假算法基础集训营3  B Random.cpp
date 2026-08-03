#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
long long gcd(long long a, long long b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--)
	{
		long long n;
		cin >> n;
		vector<long long>arr(n, 0);
		for (auto& num : arr)cin >> num;
		long long cnt = min(n, 1000LL);
		bool tem = false;
		for (int i = 0; i < cnt; i++)
		{
			for (int j = i + 1; j < cnt; j++)
			{
				if (gcd(arr[i], arr[j]) > 1)
				{
					cout << arr[i] << ' ' << arr[j] << '\n';
					tem = true;
					break;
					
				}
			}
			if (tem)break;
		}
		if (tem)continue;
		cout << -1 << '\n';

	}
	return 0;
}