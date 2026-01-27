#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int>arr;
	for (int i = 1; i <= 100; i++)arr.push_back(i);
	auto it=lower_bound(arr.begin(), arr.end(), 10);
	cout << *it << ' ' << it - arr.begin() + 1<<' ';
	it=upper_bound(arr.begin(), arr.end(), 10);
	cout <<*it<<' ' << it - arr.begin() + 1;
	return 0;
}