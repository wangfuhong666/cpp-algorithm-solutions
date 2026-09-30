#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	vector<int>arr1(m);
	vector<int>arr2(n);
	for (auto& num : arr1)cin >> num;
	for (auto& num : arr2)cin >> num;
	sort(arr1.begin(), arr1.end());
	long long count = 0;
	for (int i = 0; i < n; i++)
	{
		auto it = lower_bound(arr1.begin(), arr1.end(), arr2[i]);
		if (it == arr1.end())
		{
			count += abs(arr2[i] - arr1[m - 1]);
			continue;
		}
		if (it == arr1.begin())
		{
			count += abs(arr2[i] - arr1[0]);
			continue;
		}
		if(*it==arr2[i])continue;

		count += min(abs(*it - arr2[i]), abs(*(it - 1) - arr2[i]));
		
	}
	cout << count;
	return 0;
}