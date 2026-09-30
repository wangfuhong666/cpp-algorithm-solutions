#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{

	double x = 1.0;
	int cnt = 0;
	int n;
	cin >> n;
	for (int i = 364; i >= 365 - n; i--)
	{
		cnt++;
		x *= i / 365.0;
	}
	printf("%.4lf %d", 1-x, cnt);
	return 0;
}
