//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	long long n, c;
//	cin >> n >> c;
//	vector<long long>arr(n, 0);
//	for (auto& num : arr)cin >> num;
//	sort(arr.begin(), arr.end());
//	long long l = 0, r = n - 1, mid = 0;
//	long long count = 0LL;
//	for (int i = 0; i < n; i++)
//	{
//		auto it1 = lower_bound(arr.begin(), arr.end(), arr[i] + c);
//		if (it1 == arr.end())continue;
//		auto it2 = upper_bound(arr.begin(), arr.end(), arr[i] + c);
//		count += it2 - it1;
//	}
//	cout << count;
//	return 0;
//}