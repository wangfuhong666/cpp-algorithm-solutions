#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int>arr;
	
	for (int i = 0; i <= 15; i++)arr.push_back(2 * i + 5);
	for (auto num : arr)cout << num << ' ';
	cout << endl;
	int n = arr.size();
	vector<int>diff1(n + 1);
	diff1[0] = arr[0];
	for (int i = 1; i < n; i++)diff1[i] = arr[i] - arr[i - 1];
	for (auto num : diff1)cout << num << ' ';
	cout << endl;
	vector<int>diff2 = diff1;
	diff2[0] = diff1[0];
	for (int i = 1; i <= n; i++)diff2[i] = diff1[i] - diff1[i - 1];
	for (auto num : diff2)cout << num << ' ';
	return 0;
}