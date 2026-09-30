#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
long long qpow(long long a, long long b,long long p)
{
	long long res = 1LL;
	while (b != 0)
	{
		if (b & 1)res = res * a % p;
		a = a * a % p;
		b >>= 1;

	}
	return res;
}
int main()
{
	long long a, b, p;
	cin >> a >> b >> p;

	printf("%lld^%lld mod %lld=%lld", a, b, p, qpow(a,b,p));
	return 0;
}