#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>arr(n, 0);
	for (auto& num : arr)cin >> num;
	long long sum = 0LL;
	sort(arr.begin(), arr.end());
	for (int i = n - 1; i >=( n+ 1 ) / 2; i--)sum += arr[i] - arr[n - 1 - i ];
	cout << sum;
	
	return 0;
}