#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
long long test(vector<int>& arr, int l, int r)
{
	if (l == r)return arr[l];
	int mid = (l + r) / 2;
	long long res = max(test(arr, l, mid), test(arr, mid + 1, r));
	long long summaxl = LLONG_MIN, summaxr = LLONG_MIN;
	long long curl = 0LL, curr = 0LL;
	for (int i = mid; i >= l; i--)
	{
		curl += arr[i];
		summaxl = max(summaxl, curl);
	}
	for (int i = mid+1; i <= r; i++)
	{
		curr += arr[i];
		summaxr = max(summaxr, curr);
	}
	return max(res, summaxl + summaxr);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int>arr(n);
	for (auto& num : arr)cin >> num;
	cout << test(arr, 0, n - 1);
	return 0;
}