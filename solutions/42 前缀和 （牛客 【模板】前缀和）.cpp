#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
vector<long long> sum(vector<int>&arr)
{
	vector<long long>sum1;
	sum1.push_back(0);
	sum1.push_back(arr[0]);
	for (int i = 1; i < arr.size(); i++)
	{
		sum1.push_back(arr[i]+sum1[i]);
	}
	return sum1;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++)cin >> arr[i];
	vector<long long>f = sum(arr);
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		cout << f[r] - f[l-1] << endl;
	}
	

	return 0;
}
