#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>a;
	for (int i = 0; i < 10; i++)
	{
		a.push_back(i + 1);
	}
	for (auto m : a)
	{
		cout << m << ' ';
	}
	cout << endl;
	auto it=a.erase(a.begin()+3, a.begin() + 6);
	for (auto m : a)
	{
		cout << m << ' ';
	}
	cout << endl;
	return 0;
}