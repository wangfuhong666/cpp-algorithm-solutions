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
		int a, b;
		cin >> a >> b;
		if (a == 0)
		{
			cout << string(b, '1') << '\n';
			continue;
		}
		if (b == 0)
		{
			cout << string(a, '0') << '\n';
			continue;
		}
		if (b >= a)
		{
			int tmp1 = a + 1;
			int tmp2 = b / tmp1;
			int tmp3 = b % tmp1;
			for (int i = 0; i < tmp1; i++)
			{
				int tem = tmp2;
				if (i < tmp3)tem += 1;
				else tem += 0;
				cout << string(tem, '1');
				if (i < a)cout << '0';
				
			}

		}
		else
		{
			int tmp1 = b + 1;
			int tmp2 = a / tmp1;
			int tmp3 = a % tmp1;
			for (int i = 0; i < tmp1; i++)
			{
				int tem = tmp2;
				if (i < tmp3)tem += 1;
				else tem += 0;
				cout << string(tem, '0');
				if (i < b)cout << '1';

			}
		}
		cout << '\n';
	}
	return 0;
}