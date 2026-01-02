//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include <utility>
//#include<algorithm>
////pair数组<第几段铁路，乘坐这段铁路的次数>1->1-2,i--->i-i+1  push_back
////存储这段铁路的ABC值为了方便写代码，i表示i段铁路   n
////1-3 1  +1；；； 2   +1
//// 9-12  9-11+1
////12-9   11-9 +1
////sum i.second*A second*A*B+C
//using namespace std;
//struct price
//{
//	int A;
//	int B;
//	int C;
//};
//int main()
//{
//	
//	int n, m;
//	cin >> n >> m;
//	vector<int>diff((int)1e5 + 10);
//	vector<int>arr(m, 0);
//	vector<price>subprice(n);
//	for (auto& num : arr)cin >> num;
//	for (int i = 1; i < n; i++)cin >> subprice[i].A >> subprice[i].B >> subprice[i].C;
//	for (int i = 0; i < m - 1; i++)
//	{
//		int a = min(arr[i], arr[i + 1]);
//		int b = max(arr[i], arr[i + 1])-1;
//		diff[a]++;
//		diff[b + 1]--;
//
//	}
//	vector<long long>sum(n, 0);
//	for (int i = 1; i < n; i++)sum[i] = sum[i - 1] + diff[i];
//	long long summin = 0LL;
//	for (int i = 1; i < n; i++)
//	{
//		long long cost = min(sum[i] * subprice[i].A, sum[i] * subprice[i].B + subprice[i].C);
//		summin += cost;
//	}
//		
//	cout << summin;
//
//	return 0;
//}