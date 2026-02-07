#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		vector<long long >arrl(n, 0);
		vector<long long >arrr(m, 0);
		long long suml = 0LL, sumr = 0LL;
		for (int i = 0; i < n; i++)
		{
			cin >> arrl[i];
			suml += arrl[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> arrr[i];
			sumr += arrr[i];
		}
		if (suml == sumr)
		{
			cout << 1 << '\n';
			continue;
		}
		sort(arrl.begin(), arrl.end());
		sort(arrr.begin(), arrr.end());
		if (suml > sumr)
		{
			long long cnt1 = 0LL;
			long long i = n - 1;
			while (i>=0&&suml > sumr)
			{
				suml -= arrl[i--];
				cnt1++;
			}
			cout << cnt1 << '\n';
		}
		else
		{
			long long cnt1 = 0LL;
			long long i = m - 1;
			while (i >= 0 && sumr > suml)
			{
				sumr -= arrr[i--];
				cnt1++;
			}
			cout << cnt1 << '\n';
		}
	}
	return 0;
}