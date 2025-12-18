//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<cstdlib>
//using namespace std;
//
//int main()
//{
//	int arr[] = { 1,5,2,4,3 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int* dp = (int*)malloc(len * sizeof(int));
//	////dp[j] + 1 > dp[i]&& arr[j] < arr[i]
//	////arr 1  5  2  4  3
//	////dp  1  2  2  1  1
//	////i=1,j=0
//	////i=2 j=0,j=1 dp[2]=2
//	////i=3 j=0 dp[3]=2 j=1,j=2 dp[3]=3
//	////i=4
//	for (int i = 0; i < len; i++)
//	{
//		dp[i] = 1;
//	}
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (dp[j] + 1 > dp[i]&& arr[j] < arr[i])
//			{
//				dp[i] = dp[j] + 1;
//			}
//		}
//	}
//	int max = dp[0];
//	for (int i = 0; i < len; i++)
//	{
//		if (dp[i] > max)
//		{
//			max = dp[i];
//		}
//	}
//	cout << max << endl;
//
//}