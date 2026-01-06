////#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//vector<int> searchRange(vector<int>& nums, int target) 
//{
//	vector<int>ret;
//	int l = 0, r = nums.size() - 1, mid = 0;
//	while(l < r)
//	{
//		mid = (l + r) / 2;
//		if (nums[mid] < target) l = mid + 1;
//		else r = mid;
//	}
//	if (nums[l] == target)ret.push_back(l);
//	else ret.push_back(-1);
//	l = 0; r = nums.size() - 1; mid = 0;
//	while(l < r)
//
//	{
//		mid = (l + r+1) / 2;
//		if (nums[mid] <= target) l = mid;
//		else r = mid - 1;
//	}
//	if (nums[l] == target)ret.push_back(l);
//	else ret.push_back(-1);
//	return ret;
//
//}
//int main()
//{
//	vector<int>arr1{ 5,7,7,8,8,10 };
//	vector<int>arr = searchRange(arr1, 8);
//	for (auto num : arr)cout << num << ' ';
//	return 0;
//}