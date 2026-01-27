#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>arr{ 2150, 1830, 1050, 3210, 2890, 4120, 1560, 
		2010, 3580, 1290,3070, 1980, 2450, 1730, 4320, 2290, 
		2760, 3850, 1140, 4510,2980, 2570, 3420, 1680, 1360, 
		4090, 2310, 3650, 1870, 2190,
		1420, 2650, 3980, 1790, 4230, 2810, 3370, 1250, 2050, 1920,
		3710, 2480, 1630, 4450, 2790, 1380, 2950, 3120, 1810, 2670,
		3520, 1940, 2280, 3060, 1590, 2410, 3890, 1720, 2550, 3310
	};
	cout << "原数组为：";
	for (auto num : arr)cout << num << ' ';
	cout << endl <<endl<<endl<< "将其前缀和后的结果为：";
	vector<long long>sum(arr.size() + 1, 0);
	for (int i = 1; i <= arr.size(); i++)sum[i] = sum[i - 1] + arr[i - 1];
	for (auto num : sum)cout << num << ' ';
	cout << endl << endl << endl << "将这个前缀和数组差分后的结果为：";
	vector<long long>diff(arr.size(), 0);
	for (int i = 0; i < arr.size(); i++)diff[i] = sum[i + 1] - sum[i];
	for (auto num : diff)cout << num << ' ';
	cout << endl << endl << endl << "发现什么有意思的事情了吗？";
	return 0;
}
