//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<vector>
//#include<cstdlib>
//using namespace std;
//bool judge(vector<int>& arrn, vector<int>& arrm, int n, int m)
//{
//	for (int i = 0; i < arrn.size(); i++)
//	{
//		if (n == arrn[i] && m == arrm[i])return true;
//	}
//	return false;
//}
//int main()
//{
//	srand(time(nullptr));
//	int n, m;
//	cin >> n >> m;
//	vector<int>arrn;
//	vector<int>arrm;
//	for (int i = 0; i < n * m;)
//	{
//		int x = rand() % n + 1;	
//		int y = rand() % m + 1;
//		if (!judge(arrn, arrm, x, y))
//		{
//			arrn.push_back(x);
//			arrm.push_back(y);
//			i++;
//		}
//	}
//	for (int i = 0; i < n * m; i++)
//	{
//		cout << arrn[i] << ' ';
//		if (m != 1)cout << arrm[i];
//		cout << endl;
//	}
//	return 0;
//}
//
