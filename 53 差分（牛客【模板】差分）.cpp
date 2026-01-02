//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int n, m;
//	cin >> n>>m;
//	vector<long long>arr(n,0);
//	vector<long long>diff(n+2,0);
//	vector<long long>sum(n+1,0);
//	for (auto& num : arr)cin >> num;
//	diff[1] = arr[0];
//	for (int i = 2; i <= n; i++)diff[i] = arr[i-1] - arr[i - 2];
//	while (m--)
//	{
//		int l, r, k;
//		cin >> l >> r >> k;
//		diff[l] += k;
//		diff[r + 1] -= k;
//	}
//	for (int i = 1; i <= n; i++)sum[i] = sum[i - 1] + diff[i];
//	for (int i = 1; i <= n; i++)cout<<sum[i]<<' ';
//
//	return 0;
//}