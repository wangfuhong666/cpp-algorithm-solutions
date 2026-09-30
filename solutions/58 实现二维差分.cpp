#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int>>arr(10, vector<int>(10));
	int ppp = 1;
	for (auto& row : arr)for (auto& num : row)num = ppp++;
	//for (auto& row : arr)
	//{
	//for (auto num : row)cout << num << ' ';
	//	cout << endl;
	//}
	vector<vector<int>>sum(11, vector<int>(11));
	for (int i = 1; i <= 10; i++)for (int j = 1; j <= 10; j++)sum[i][j] = arr[i - 1][j - 1];
	for (int i = 1; i <= 10; i++)for (int j = 1; j <= 10; j++)sum[i][j] += sum[i ][j - 1];
	for (int i = 1; i <= 10; i++)for (int j = 1; j <= 10; j++)sum[i][j] += sum[i - 1][j];
	for (auto& row : sum)
	{
		for (auto num : row)cout << num << ' ';
		cout << endl;
	}
	vector<vector<int>>diff(11, vector<int>(11)), difftem(11, vector<int>(11));
	//for (int i = 1; i <= 10; i++)for (int j = 1; j <= 10; j++)diff[i][j] = sum[i][j];
	for (int i = 1; i <= 10; i++)for (int j = 1; j <= 10; j++)difftem[i][j] = sum[i][j]-sum[i][j - 1];
	for (int i = 1; i <= 10; i++)for (int j = 1; j <= 10; j++)diff[i][j] = difftem[i][j]-difftem[i - 1][j];
	for (auto& row : diff)
	{
		for (auto num : row)cout << num << ' ';
		cout << endl;
	}
	return 0;
}