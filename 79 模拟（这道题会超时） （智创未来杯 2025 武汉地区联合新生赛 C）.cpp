//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//void test(string& s, int pos,long long& x, long long& y)
//{
//	if (s[pos] == 'L')x -= 1;
//	if (s[pos] == 'R')x += 1;
//	if (s[pos] == 'U')y += 1;
//	if (s[pos] == 'D')y -= 1;
//}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//	int n, q;
//	cin >> n >> q;
//	string s;
//	cin >> s;
//	while (q--)
//	{
//		bool judge = false;
//		long long posx = 0;
//		long long posy = 0;
//		long long l, r, x, y;
//		cin >> l >> r >> x >> y;
//		if (x == 0 && y == 0)
//		{
//			cout << "YES" << endl;
//			continue;
//		}
//		for (int i = 0; i < l - 1; i++)
//		{
//			test(s, i, posx, posy);
//			if (posy == y && posx == x)
//			{
//				judge = true;
//				break;
//			}
//		}
//		for (int i = r; i < n; i++)
//		{
//			if (judge)break;
//			test(s, i, posx, posy);
//			if (posy == y && posx == x)
//			{
//				judge = true;
//				break;
//			}
//		}
//		if (judge)cout << "YES" << endl;
//		else cout << "NO" << endl;
//
//	}
//	return 0;
//}