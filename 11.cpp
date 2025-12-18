//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cstdlib>
//#include<cstring>
//#include<iomanip>
//#include<cmath>
//#include<ctime>
//#define MAX 93
//using namespace std;
//
//long long arr[MAX];
////dp
//long long  fun(int n)
//{
//	if (arr[n] != 0)
//	{
//		return arr[n];
//	}
//	else
//	{
//		if (n == 1 || n == 2) { arr[n] = 1; return arr[n]; }
//		else {arr[n] = fun(n - 1) + fun(n - 2); return arr[n];}
//	}
//	
//	
//}
//
//int main()
//{
//	auto A = clock();
//	memset(arr, 0, sizeof arr);
//	fun(92);
//	for (int i = 1; i <= 92; ++i) {
//		
//		cout << "F_" << setw(2) << i << " = " << setw(20) << arr[i];
//		
//		if (i % 5 == 0) {
//			cout << endl;
//		}
//		else {
//			cout << "  ";  
//		}
//	}
//	auto B = clock();
//	cout << endl;
//	cout << "×ÜÓÃÊ±£º " << llabs((long long)(B - A)) << "ms";
//	
//	return 0;	
//}
