//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//#include<utility>
//using namespace std;
//bool cmp(pair<int, int>a, pair<int, int>b)
//{
//	return a.second > b.second;
//}
//int main()
//{
//	int M, N, K, L, D;
//	cin >> M >> N >> K >> L >> D;
//	
//	unordered_map<int, int>mpx;
//
//	unordered_map<int, int>mpy;
//	for (int i = 0; i < D; i++)
//	{
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		if (x1 == x2)mpy[min(y1, y2)]++;
//		if (y1 == y2 )mpx[min(x1, x2)]++;
//	}
//	vector<pair<int, int>>cntx(mpx.begin(), mpx.end());
//	vector<pair<int, int>>cnty(mpy.begin(), mpy.end());
//	sort(cntx.begin(), cntx.end(), cmp);
//	sort(cnty.begin(), cnty.end(), cmp);
//	vector<int>ansx, ansy;
//	for (int i = 0; i < K; i++)ansx.push_back(cntx[i].first);
//	for (int i = 0; i < L; i++)ansy.push_back(cnty[i].first);
//	sort(ansx.begin(), ansx.end());
//	sort(ansy.begin(), ansy.end());
//	for (int i = 0; i < K; i++)
//	{
//		cout << ansx[i];
//		if (i < K - 1)cout << ' ';
//	}
//	cout << endl;
//	for (int i = 0; i < L; i++)
//	{
//		cout << ansy[i];
//		if (i < L - 1)cout << ' ';
//	}
//	
//	return 0;
//}