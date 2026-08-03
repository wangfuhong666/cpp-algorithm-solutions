#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;
string operator-(string a,string b)
{
	string res = "";
	for (int i = 0; i < a.size(); i++)
	{
		res += a[i] - b[i] + '0';
	}
	return res;
}
int main()
{
	string s1 = "111", s2 = "222", s3 = "999";
	
	cout << s3 - s2 - s1;
	return 0;
}