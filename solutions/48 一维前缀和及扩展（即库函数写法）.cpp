#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

//sum[i]=sum[i-1]  x  a[i]
//c=a+b
//c-a=b
// a=10111
// b=11100
// c=a^b=01011
// b=c^a成立
// 01011
// 10111
// 11100
int par(int a, int b)
{
	return a ^ b;
}
int main()
{
	//前缀和
	vector<int>arr{ 5,6,8,4,2,5,9,6,89,65,23 };
	vector<int>sum(arr.size() + 1, 0);
	partial_sum(arr.begin(), arr.end(), sum.begin() + 1);
	for (auto m : arr)cout << m << ' ';
	cout << endl;
	for (auto m : sum)cout << m << ' ';
	//前缀异或和
	vector<int>arr{ 1,5,6,8,9,45,68,95,421,568,95,4,1,23,6,98,753,159,456,7,77,888,999,5,4,2,3,46,52,78,93,46,18,753,146,236 };
	vector<int>sum1(arr.size() + 1, 0);
	vector<int>sum2(arr.size() + 1, 0);
	for (int i = 1; i <= arr.size(); i++)sum1[i] = sum1[i - 1] ^ arr[i-1];
	for (auto m : arr)cout << m << ' ';
	cout << endl;
	for (auto m : sum1)cout << m << ' ';
	cout << endl;
	partial_sum(arr.begin(), arr.end(), sum2.begin() + 1, par);
	for (auto m : sum2)cout << m << ' ';

	return 0;
}