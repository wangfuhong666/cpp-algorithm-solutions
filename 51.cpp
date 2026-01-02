//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<numeric>
//using namespace std;
//struct price
//{
//	int x;
//	int y;
//	int v; 
//};
//bool cmp(price A, price B)
//{
//	return A.x < B.x;
//}
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<price>arr(n);
//	for (auto& m : arr)cin >> m.x >> m.y >> m.v;
//	sort(arr.begin(), arr.end(), cmp);
//	int max = 0;
//	int l = 0;
//
//	for (int r = 0; r < n; r++)
//	{
//		while (arr[r].x - arr[l].x >= m)l++;
//
//	}
//	return 0;
//}