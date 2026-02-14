#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int>arr(n, 0),tmp(n,0);
	for (int i = 0; i < n ; i++)
	{
		int num;
		cin >> num;
		arr[i] = num;
		tmp[i] = num;
	}
	sort(tmp.begin(), tmp.end());
	long long sum = 0LL;
	for (int i = 0; i < n; i++)
	{
		auto it1=lower_bound(tmp.begin(), tmp.end(), arr[i]);
		auto it2=upper_bound(tmp.begin(), tmp.end(), arr[i]);

		int tem1= it1 - tmp.begin();
		int tem2= it2 - tmp.begin();
		if ((tem2-1)*10 >= 8 * (n-1))
		{
		
			sum += arr[i];
		}
	}
	cout << sum;
	return 0;
}