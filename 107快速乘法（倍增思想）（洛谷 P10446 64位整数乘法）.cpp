#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;
long long qmul(long long a, long long b, long long p)
{
	long long res = 0LL;
	while (b != 0)
	{
		if (b & 1)res =( res + a)% p;
		a = a * 2 % p;
		b >>= 1;
	}
	return res;
}
int main()
{
	long long a, b, p;
	cin >> a >> b >> p;
	cout << qmul(a, b,p);
	return 0;
}