//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//bool judge(string s)
//{
//	int l = 0;
//	int r = s.size() - 1;
//	while (l <= r)
//	{
//		if (s[l] != s[r])return false;
//		l++;
//		r--;
//	}
//	return true;
//}
//int mon_day(int year, int month)
//{
//	if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2)return 29;
//	int day;
//	switch (month)
//	{
//		case 1:
//		case 3:
//		case 5:
//		case 7:
//		case 8:
//		case 10:
//		case 12:
//			day = 31;
//			break;
//		case 4:
//		case 6:
//		case 9:
//		case 11:
//			day = 30;
//			break;
//		case 2:
//			day = 28;
//			break;
//	}
//		
//	return day;
//}
//int main()
//{
//
//	long long t1, t2,count=0LL;
//	cin >> t1 >> t2;
//	string s; 
//	s= to_string(t1);
//	if (judge(s))count++;
//
//	while (t1 != t2)
//	{
//		int year = t1 / 10000;
//		int month = (t1 / 100) % 100;
//		int day = t1 % 100;
//		day++;
//		if(day> mon_day(year,month)){day-= mon_day(year, month);month++;}
//		if (month > 12) { month -= 12; year++;}
//		t1 = year * 10000 + month * 100 + day;
//		s = to_string(t1);
//		if (judge(s))count++;
//		
//	}
//	cout << count;
//	return 0;
//}