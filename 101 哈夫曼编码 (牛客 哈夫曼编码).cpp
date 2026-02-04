#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	priority_queue<long long, vector<long long>, greater<long long>>q;
	for (int i = 0; i < n; i++)
	{
		long long tem;
		cin >> tem;
		q.push(tem);
	}
	if (n == 1)
	{
		cout << q.top();
		return 0;
	}
	long long cnt = 0LL;
	while (q.size()>1)
	{
		long long tem1 = q.top();
		q.pop();
		long long tem2 = q.top();
		q.pop();
		q.push(tem1 + tem2);
		cnt += tem1 + tem2;
	}
	cout << cnt;
	return 0;
}