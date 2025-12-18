//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int judge(char strs[][300], int n, int num)
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
//	int n = 3;
//	int k = 0;
//	putchar('"');
//	while ((judge(strs, n, k)))
//	{
//		int st = 1;
//		char tem = strs[0][k];
//		for (int j = 1; j < n; j++)
//		{
//
//			if (strs[j][k] != tem)
//			{
//				st = 0;
//				break;
//			}
//		
//		}
//		
//		if (st)
//		{
//			putchar(tem);
//			
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