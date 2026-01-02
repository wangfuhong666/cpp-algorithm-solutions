//#define _CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//#include<iostream>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		vector<int>arr1(5, 0);
//		for (int i = 0; i < 5; i++)
//		{
//			for (int j = 0; j < 5; j++)
//			{
//				char ch;
//				cin >> ch;
//				//if (ch == '0')arr1[i] += (1<<j);
//				//这两种写法是一个意思，更推荐下面的这种写法
//				if (ch == '0')arr1[i] |= (1<<j);
//
//			}
//		}
//		
//		int minsize = 1000;
//		for (int st = 0; st < (1 << 5); st++)
//		{
//			int count = 0;
//			vector<int>arr = arr1;
//			int push = st;
//			for (int i = 0; i < 5; i++)
//			{
//				for (int j = 0; j < 5; j++)if ((push >> j) & 1)count++;
//				arr[i] = arr[i] ^ push ^ (push >> 1) ^ (push << 1);
//				if (i < 4) {
//					arr[i + 1] ^= push;
//				}
//				arr[i] &= (1 << 5) - 1;
//				push = arr[i];
//			}
//			if (arr[4] == 0)minsize = min(count, minsize);
//		}
//		if (minsize == 1000 || minsize > 6)cout << -1<<endl;
//		else cout<< minsize<<endl;
//	}
//
//
//
//	return 0;
//}