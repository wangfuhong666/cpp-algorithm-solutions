#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{

	int a = 5, b = -8;
	int c = a ^ b;
	int d = ~(a ^ b);
	cout << c << ' ' << d<<endl;

	return 0;
}