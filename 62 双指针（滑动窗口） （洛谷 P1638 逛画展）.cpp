//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	vector<int>arr(n + 1, 0);
//	unordered_map<int, int>mp;
//	int count = 0;
//	for (int i = 1; i <= n; i++)cin >> arr[i];
//	int l = 1,r=1;
//	int minlen = 0x3f3f3f3f;
//	int anx = 0, any = 0;
//	while(r <= n)
//	{
//		
//		if (mp[arr[r]] == 0)count++;
//		mp[arr[r]]++;
//		while (count == m)
//		{
//			while (mp[arr[l]] > 1)
//			{
//				mp[arr[l]]--;
//				l++;
//			}
//			int len = r - l + 1;
//			if (len < minlen||(len == minlen&&l<anx))
//			{
//				minlen = len;
//				anx = l;
//				any = r;
//			}
//			mp[arr[l]]--;
//			if (mp[arr[l]] == 0)count--;
//			l++;
//		}
//		r++;
//
//
//	}
//	cout << anx << ' ' << any;
//	return 0;
//}