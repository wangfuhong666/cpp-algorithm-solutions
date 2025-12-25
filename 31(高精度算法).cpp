//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<cstdlib>
//#include<cstring>
//#include<cstdio>
//#define MAX (10000 + 6)
//using namespace std;
////高精度比较函数（s1>=s2 true s1<s2 false）
//bool cmp_high(string s1, string s2)
//{
//	if (s1.size() > s2.size())return true;
//	else if (s1.size() < s2.size())return false;
//	else
//	{
//		if (s1 >= s2)return true;
//		else return false;
//	}		
//}
//
//string add_N(string s1, string s2)
//{
//	int arr1[MAX];
//	int arr2[MAX];
//	int arr3[MAX];
//	memset(arr1, 0, sizeof arr1);
//	memset(arr2, 0, sizeof arr2);
//	memset(arr3, 0, sizeof arr3);
//	long long len1 = s1.size();
//	long long len2 = s2.size();
//	long long len = len1 >= len2 ? len1 : len2;
//	for (long long i = 0; i < len1; i++)
//	{
//		arr1[len1 - i - 1] = s1[i] - '0';
//	}
//	for (long long i = 0; i < len2; i++)
//	{
//		arr2[len2 - i - 1] = s2[i] - '0';
//	}
//	for (long long i = 0; i <= len; i++)
//	{
//		arr3[i] += arr1[i] + arr2[i];
//		if (arr3[i] >= 10)
//		{
//			arr3[i + 1] += arr3[i] / 10;
//			arr3[i] %= 10;
//		}
//	}
//	long long lenmax = len;
//	if (arr3[len] != 0)
//	{
//		lenmax++;
//	}
//	string s3;
//	for (long long i = lenmax - 1 ; i >= 0; i--)
//	{
//		s3 += arr3[i]+'0';
//	}
//	return s3;
//}
//string sub_N(string &s1, string &s2)
//{
//	int arr1[MAX];
//	int arr2[MAX];
//	int arr3[MAX];
//	bool judge_sign = false;
//	string s_min, s_max;
//	memset(arr1, 0, sizeof arr1);
//	memset(arr2, 0, sizeof arr2);
//	memset(arr3, 0, sizeof arr3);
//
//	if (s1 == s2)return "0";
//	else
//	{
//		cmp_high(s1, s2) ? (s_max = s1, s_min = s2, judge_sign = false) : (s_max = s2, s_min = s1, judge_sign=true);
//	}
//	long long len1 = s_max.size();
//	long long len2 = s_min.size();
//	long long len = len1 >= len2 ? len1 : len2;
//	for (long long i = 0; i < len1; i++)
//	{
//		arr1[len1 - i - 1] = s_max[i] - '0';
//	}
//	for (long long i = 0; i < len2; i++)
//	{
//		arr2[len2 - i - 1] = s_min[i] - '0';
//	}
//
//	for (long long i = 0; i <= len - 1; i++)
//	{
//		arr3[i] += arr1[i] - arr2[i];
//		if (arr3[i] < 0)
//		{
//			arr3[i] += 10;
//			arr3[i + 1] -= 1;
//		}
//	}
//	
//	
//	
//	long long len_res = len - 1;
//	while (len_res > 0 && arr3[len_res] == 0)
//	{
//		len_res--;
//	}
//	string s3;
//	if (judge_sign && arr3[len_res] != 0) {
//		s3 += '-';
//	}
//	
//
//
//	for (long long i = len_res ; i >= 0; i--)
//	{
//		s3 += arr3[i] + '0';
//	}
//	if (s3 == "-0") {
//		s3 = "0";
//	}
//	return s3;
//	 
//}
//
//int main()
//{
//	string s1, s2;
//	getline(cin, s1);
//	getline(cin, s2);
//	string res = sub_N(s1, s2);
//	cout <<  res;
//	return 0;
//}