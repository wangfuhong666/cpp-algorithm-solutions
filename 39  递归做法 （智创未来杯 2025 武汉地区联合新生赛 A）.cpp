////#define _crt_secure_no_warnings
//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;
//// i Ыљга i+1
////i==0------>s.size()-2
//
//void text(string s, string t,int t1,int t2,int pos, vector<int>&v)
//{
//	if (t1 >= t.size() )
//	{
//		v[pos] += 1;
//		return ;
//	}	
//	size_t num = t2;
//	while (true) {
//		num = s.find(t[t1], num);
//		if (num == string::npos) {
//			return;
//		}
//		text(s, t, t1 + 1, num+1, pos,v);
//		num++;
//	}
//
//}
//int main()
//{
//	string s;
//	cin >> s;
//	vector<string>u{"ccnu","hust","hzau","whu","whut"};
//	vector<int>v(5);
//	sort(u.begin(), u.end());
//	fill(v.begin(), v.end(), 0);
//	for (int i = 0; i < 5; i++)
//	{
//		text(s, u[i], 0, 0, i,v);
//	}
//	int max = v[0];
//	for (int i = 1; i < 5; i++)
//	{
//		if (v[i] > max)max = v[i];
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		if (v[i] == max)
//		{
//			cout << u[i] << ' ' << v[i];
//			break;
//		}
//	}
//	return 0;
//}