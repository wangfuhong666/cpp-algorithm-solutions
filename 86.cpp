//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//bool test(string& s, string& ss)
//{
//	ss = "";
//	bool judge = false;
//	for (int i = 0; i < s.size() - 2; )
//	{
//		if (s[i] == 'L' && s[i + 1] == 'Q')
//		{
//			if (s[i + 2] == 'Q')
//			{
//				judge = true;
//				i += 2;
//				continue;
//			}
//		}
//		ss += s[i];
//		i++;
//	}
//	return judge;
//}
//int main()
//{
//	string s, ss,stem;
//	cin >> s;
//	if (s.size() == 1)
//	{
//		cout << s;
//		return 0;
//	}
//	if (s.size() == 2)
//	{
//		cout << s;
//		return 0;
//	}
//	stem += s[s.size() - 2];
//	stem += s[s.size() - 1];
//	long long i = 0;
//	while (test(s, ss))
//	{
//		i++;
//		swap(s, ss);
//	}
//	if (i % 2 == 0)cout << ss + stem;
//	else cout << s + stem;
//	return 0;
//}