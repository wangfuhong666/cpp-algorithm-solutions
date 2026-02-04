#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
using PDD = pair<double, double>;
bool cmp(PDD a, PDD b)
{
	return a.second < b.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	int cnt = 0;
	int n, d;
	while (cin >> n >> d && (n != 0 || d != 0))
	{
		cnt++;
		vector<PDD>arr(n);
		bool judge = false;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			if (y > d)judge = true;
			double t = sqrt(d * d - y * y);
			arr[i].first = x - t;
			arr[i].second = x + t;
		}
		if (judge)
		{
			cout << "Case " << cnt << ": " << -1 << '\n';
			continue;
		}
		sort(arr.begin(), arr.end(), cmp);
		double l = arr[0].first, r = arr[0].second;
		int res = 1;
		for (int i = 1; i < n; i++)
		{
			if ( arr[i].first>r + 1e-9)
			{
				res++;
				l = arr[i].first;
				r = arr[i].second;
			}				
		}
		cout << "Case " << cnt << ": " << res << '\n';

	}
	return 0;
}