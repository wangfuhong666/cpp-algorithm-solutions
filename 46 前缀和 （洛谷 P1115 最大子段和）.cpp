#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long>sum(vector<int>& arr)
{
	vector<long long>f;
	f.push_back(0);
	for (int i = 0; i < arr.size(); i++)f.push_back(f[i] + arr[i]);
	return f;
}
vector<long long>summin(vector<long long>& f)
{
	vector<long long>fmin;
	fmin.push_back(0);
	
	long long sum_min = f[0];
	for (int i = 1; i < f.size(); i++)
	{
		sum_min = min(f[i], sum_min);
		fmin.push_back(sum_min);
	}
	return fmin;
}
int main()
{
	int n;
	cin >> n;
	vector<int>arr(n, 0);
	for (int i = 0; i < n; i++)cin >> arr[i];
	vector<long long>f = sum(arr);
	vector<long long>fmin = summin(f);

	long long maxsum = -0x3f3f3f3f;
	for (int i = 1; i < n + 1; i++)maxsum = max(maxsum, f[i] - fmin[i - 1]);
	cout << maxsum;
	

	return 0;
}