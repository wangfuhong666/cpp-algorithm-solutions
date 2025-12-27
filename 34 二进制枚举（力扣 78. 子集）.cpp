//#define _crt_secure_no_warnings
//#include<iostream>
//#include<string>
//#include<cstdio>
//#include<vector>
//using namespace std;
//
//vector<vector<int>> subsets(vector<int>& nums)
//{
//	vector<vector<int>>ret;
//	int n = nums.size();
//	for (int st = 0; st < (1 << n); st++)
//	{
//		vector<int>tmp;
//		for (int i = 0; i < n; i++)
//		{
//			if ((st >> i) & 1)tmp.push_back(nums[i]);
//		}
//		ret.push_back(tmp);
//	}
//	return ret;
//
//}
//
//int main()
//{
//	vector<int>arr{ 1,2,3 };
//	for (auto m : subsets(arr))
//	{
//		for (auto k : m)
//		{
//			cout << k;
//		}
//		cout << endl;
//	}
//		return 0;
//}