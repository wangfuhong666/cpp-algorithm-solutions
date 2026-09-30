#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define MAX (10000 + 6)
using namespace std;
string add_N(string s1, string s2)
{
	int arr1[MAX];
	int arr2[MAX];
	int arr3[MAX];
	memset(arr1, 0, sizeof arr1);
	memset(arr2, 0, sizeof arr2);
	memset(arr3, 0, sizeof arr3);
	long long len1 = s1.size();
	long long len2 = s2.size();
	long long len = len1 >= len2 ? len1 : len2;
	for (long long i = 0; i < len1; i++)
	{
		arr1[len1 - i - 1] = s1[i] - '0';
	}
	for (long long i = 0; i < len2; i++)
	{
		arr2[len2 - i - 1] = s2[i] - '0';
	}
	for (long long i = 0; i <= len; i++)
	{
		arr3[i] += arr1[i] + arr2[i];
		if (arr3[i] >= 10)
		{
			arr3[i + 1] += arr3[i] / 10;
			arr3[i] %= 10;
		}
	}
	long long lenmax = len;
	if (arr3[len] != 0)
	{
		lenmax++;
	}
	string s3;
	for (long long i = lenmax - 1 ; i >= 0; i--)
	{
		s3 += arr3[i]+'0';
	}
	return s3;
}
int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	string res = add_N(s1, s2);
	cout << s1 << ' ' << '+' << ' ' << s2 << ' ' << '=' << ' ' << res <<endl;
/*	for (int i = 1; i < 20000; i++)
	{
		s1 = to_string(i);
		s2 = to_string(i+1);
		string res = add_N(s1, s2);
		cout <<i<<' '<<'+' << ' ' << i + 1 << ' ' << '=' << ' ' <<res<<' ';
		if (i % 5 == 0) { cout << endl; }
	}*/

	return 0;
}