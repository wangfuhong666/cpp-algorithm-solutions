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
//	long long sum = 0LL;
//	vector<long long>arr_1(n, 0);
//	for (auto &num : arr_1)cin >> num, sum += num;
//	vector<long long>arr = arr_1;
//	arr.insert(arr.end(), arr_1.begin(), arr_1.end());
//	long long max_sum = 0LL, cur_sum = 0LL;
//	int l = 0, r = 0;
//	while (r < arr.size())
//	{
//		cur_sum += arr[r];
//		while (cur_sum > sum / 2)
//		{
//			cur_sum -= arr[l++];
//		}
//		max_sum = max(max_sum, cur_sum);
//		if (max_sum == sum / 2)
//		{
//			break;
//		}
//		r++;
//	}
//	cout << max_sum;
//	return 0;
//}
