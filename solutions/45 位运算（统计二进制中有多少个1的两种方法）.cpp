#define _CRT_SECURE_NO_WARNING
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//方法一与1与运算+右移法
int calc1(int x)
{
	int count = 0;
	unsigned int n = x;
	while (n)
	{
		if (n & 1)count++;
		n >>= 1;
	}
	return count;
}
//方法二x & x - 1  消1法
int calc2(int x)
{
	int count = 0;
	unsigned int n = x;
	while (n)
	{
		n &= n - 1;
		count++;
	}
	return count;
}
int main()
{
	while (true)
	{
		int n;
		cin >> n;
		cout << "方法一与1与运算+右移法的结果为：" << calc1(n) << endl;
		cout << "方法二x & x - 1  消1法的结果为：" << calc2(n) << endl;

	}
	return 0;
}