//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	int m;
//	cin >> m;
//	int n;
//	cin >> n;
//	vector<long long>arr(n, 0);
//	for (auto& num : arr)cin >> num;
//	sort(arr.begin(), arr.end());
//	long long l = 0, r = n - 1;
//	long long ans = 0LL;
//	while (l <= r)
//	{
//		ans++;
//		if (arr[l] + arr[r] <= m)l++;
//		r--;
//	}
//	cout << ans;
//	return 0;
//}