#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	//0&1=0  1&1=1 0|=1
	//<< >> > < &|^
	if (2>(1&0)) { cout << "Yes"; }
	else{ cout << "No"; }

	return 0;
}