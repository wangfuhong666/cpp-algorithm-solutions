#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//1  1 1-100 2 5
int main()
{
	int n;
	cin >> n;
	vector<int>arr(n, 0);
	for (auto& num : arr)cin >> num;
	int l = 0, r = 0;
	long long sum = 0LL, ret = -0x3f3f3f3f;
	while (r < n)
	{
		sum += arr[r];
		
		while ((arr[l] < 0||sum<0)&&l<r)sum -= arr[l++];
		ret = max(ret, sum);
		r++;			
	}
	cout << ret;
	return 0;
}