//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>	
//
//using namespace std;
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		string s;
//		cin >> s;
//		int l = 0, r = s.size() - 1;
//		vector<char>T{ 'b','d','p','q' };
//		vector<char>U{ 'n','u'};
//		bool judge = true;
//		while (l < r)
//		{
//			if (s[l] != s[r])
//			{
//				auto it1 = find(T.begin(), T.end(), s[l]);
//				auto it2 = find(T.begin(), T.end(), s[r]);
//				auto it11 = find(U.begin(), U.end(), s[l]);
//				auto it21 = find(U.begin(), U.end(), s[l+1]);
//				auto it12 = find(U.begin(), U.end(), s[r]);
//				auto it22 = find(U.begin(), U.end(), s[r-1]);
//				if (it11 != U.end() && it12 != U.end())
//				{
//					l++;
//					r--;
//					continue;
//				}
//				if (it11 != U.end() && it21 != U.end() && s[r] == 'm')
//				{
//					l += 2;
//					r--;
//					continue;
//				}
//				if (it12 != U.end() && it22 != U.end() && s[l] == 'm')
//				{
//					l ++;
//					r-=2;
//					continue;
//				}
//
//				if (s[l] == 'v' && s[l + 1] == 'v' && s[r] == 'w')
//				{
//					l += 2;
//					r--;
//					continue;
//				}
//				if (s[r] == 'v' && s[r - 1] == 'v' && s[l] == 'w')
//				{
//					l++;
//					r -= 2;
//					continue;
//				}
//				
//				if (it1 != T.end()&& it2 != T.end())
//				{
//					l++;
//					r--;
//					continue;
//				}
//				judge = false;''
//				break;				
//			}
//			l++;
//			r--;
//		}
//		if (judge)cout << "YES" << endl;
//		else cout << "NO" << endl;
//	}
//	
//	return 0;
//}