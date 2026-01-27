#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long calc(vector<int>& arr, long long a)
{
	long long count = 0LL;
	for (auto num : arr)count += num / a;
	return count;
}

int main()

{
	int n, k;
	cin >> n >> k;
	vector<int>arr(n, 0);
	for (auto& num : arr)cin >> num;
	long long  l = 1, r = ranges::max(arr), mid = -1;
	while (l < r)
	{
		mid = (l + r + 1) / 2;
		if (calc(arr, mid) >= k)l = mid;
		else r = mid - 1;
		
	}
	if (calc(arr, l) < k)cout << 0;
	else cout << l;
	return 0;
}



P1873 COCI 2011 2012 5 EKO  ¿³Ê÷