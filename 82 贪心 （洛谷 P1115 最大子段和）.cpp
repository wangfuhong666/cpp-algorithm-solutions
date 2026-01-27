//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int>arr(n, 0);
//	for (auto& num : arr)cin >> num;
//	long long sum = 0LL, ret = -0x3f3f3f3f;
//	for (auto num : arr)
//	{
//		sum += num;	
//		ret = max(ret, sum);
//		if (sum < 0)sum = 0;
//	}
//	cout << ret;
//	return 0;
//}