#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	char arr[1000];
	scanf("%[^\n]", arr);
	printf("%s", arr);
	for (int i = 1; i <= 100; i++)
	{
		cout << "-1 >>" << i << " = " << (-1 >> i) << ' ';
		if (i % 5 == 0) { cout << endl; }
	}
}