#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n;
	cin >> n;
	long long nums = 1LL << n;
	for (long long i = 0LL; i < nums; i++)
	{
		cout << (i ^ (i >> 1LL)) <<' ';
	}
	return 0;
}