#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
int bitwei(int n)
{
	unsigned int t = n;
	int cnt = 0;
	while (t != 0)
	{
		cnt++;
		t >>= 1;
	}
	return cnt;
}
int main()
{
	for (int i = -2; i <= 100; i++)cout << bitwei(i) << endl;
	return 0;
}