//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//	int n, m, k;
//	cin >> n >> m >> k;
//	vector<vector<long long>>arrarr(n, vector<long long>(m));
//	for (auto& row : arrarr)for (auto& num : row)cin >> num;
//	long long cnt = -0x3f3f3f3f;
//	for (int st1 = 0; st1 < (1 << n); st1++)
//	{
//		vector < vector<long long>>arr = arrarr;
//		int tem1 = 0;
//		long long sum = 0LL;
//		for (int i = 0; i < n; i++)
//		{
//			if ((st1 >> i) & 1)
//			{
//				tem1++;
//				for (int j = 0; j < m; j++)
//				{
//					sum += arr[i][j];
//					arr[i][j] = 0;
//				}
//
//			}
//		}
//		int tem2 = k - tem1;
//		if (tem2 < 0)continue;
//		for (int st2 = 0; st2 < (1 << m); st2++)
//		{
//			long long sum1 = 0LL;
//			vector<vector<long long>>arr1 = arr;
//			int tem3 = 0;
//			for (int i = 0; i < m; i++)
//			{
//				if ((st2 >> i) & 1)tem3++;
//			}
//			if (tem3 == tem2)
//			{
//				for (int i = 0; i < m; i++)
//				{
//					if ((st2 >> i) & 1)
//					{
//						for (int j = 0; j < n; j++)
//						{
//							sum1 += arr1[j][i];
//							arr1[j][i] = 0;
//						}
//					}
//				}
//			}
//			cnt = max(cnt, sum + sum1);
//		}
//		
//
//	}
//	cout << cnt;
//	return 0;
//}