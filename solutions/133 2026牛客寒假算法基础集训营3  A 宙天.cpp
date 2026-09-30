#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int x;
	cin >> x;
	for (int i = 0; i <= 150; i++)
	{
		if (i * (i + 1) == x)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}