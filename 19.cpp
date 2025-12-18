//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
////错误思路
//int main()
//{
//	long long n, m,F;
//	cin >> n >> m;
//	long long res = m % n;
//	if (res > 0)
//	{
//		F = m / n + 1;
//		res--;
//	}
//	else
//	{
//		F = m / n;
//	}
//	
//	for (long long i = 0LL; i < n-1; i++)
//	{
//		long long cer;
//		if (res > 0)
//		{
//			cer= m / n + 1;
//			res--;
//		}
//		else
//		{
//			cer= m / n;
//		}
//		F &= cer;
//	}
//	cout << F;
//	return 0;
//}
//正确思路


//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//using namespace std;
//int main()
//{
//	unsigned long long n, m,res=0;
//	cin >> n >> m;
//	for (int i = 60; i >= 0; i++)
//	{
//		unsigned long long tem = 1ull << i;
//		if (n * tem <= m)
//		{
//			res |= tem;
//			m -= n * tem;
//		}
//	}
//	cout << res;
//	return 0;
//}
