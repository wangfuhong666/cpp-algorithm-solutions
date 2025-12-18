//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int judge(char strs[][300],int n ,int num)
//{
//
//	for (int i = 0; i < n; i++)
//	{
//		if (strs[i][num] == '\0') 
//		{ 
//			return 0;
//		}
//	}
//	return 1;
//}
//int main()
//{
//	char strs[][300] = { "flower","flow","flight" };
//	int n=3;
//	int k = 0;
//	int arr[300];
//	putchar('"');
//	memset(arr, 0, sizeof arr);
//	while (judge(strs, n, k))
//	{
//		int j;
//		
//		for ( j = 0; j < n; j++)
//		{
//
//			arr[strs[j][k]] += 1;
//		}
//		j = 0;
//		if (arr[strs[j][k]] == n)
//		{
//			putchar(strs[j][k]);
//			arr[strs[j][k]] = 0;
//		}
//		else
//		{
//			break;
//		}
//		k++;
//	}
//
//	putchar('"');
//	
//
//	return 0;
//}