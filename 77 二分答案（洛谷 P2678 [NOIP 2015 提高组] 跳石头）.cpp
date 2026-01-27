//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//
//using namespace std;
//long long test(vector<int>& arr, long long len)
//{
//	long long count = 0LL;
//	int pos = 0;
//	for (int i = 1; i < arr.size(); i++)
//	{
//		if (arr[i] - pos < len)
//		{
//			count++;
//		}
//		else
//		{
//			pos = arr[i];
//		}
//	}
//	return count;
//}
//int main()
//{
//	int L, N, M;
//	cin >> L >> N >> M;
//	vector<int>arr(N + 2, 0);
//	for (int i = 1; i <= N; i++)cin >> arr[i];
//	arr[N + 1] = L;
//	long long l = 1, r = L, mid = -1;
//	while (l < r)
//	{
//		mid = (l + r + 1) / 2;
//		if (test(arr, mid) <= M)l = mid;
//		else r = mid - 1;
//	}
//	cout << l;
//	return 0;
//}