//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<ctime>
//#include<cmath>
//#include<vector>
//#include <iomanip>
//#include<algorithm>
//using namespace std;
//自己写的算法（可AC）
//void start(vector<vector<int>>& arr, int n, int x, int y)
//{
//	static int i = 1;
//
//
//	for (int j = x; j < arr.size() - x; j++)
//	{
//		arr[y][j] = i;
//		if (i == n * n) return;
//		i++;
//	}
//	for (int j = y + 1; j < arr.size() - y - 1; j++)
//	{
//		arr[j][arr.size() - x - 1] = i;
//		if (i == n * n) return;
//		i++;
//	}
//	for (int j = arr.size() - y - 1; j >= x; j--)
//	{
//		arr[arr.size() - x -1][j] = i;
//		if (i == n * n) return;
//		i++;
//	}
//	for (int j = arr.size() - y - 1 - 1; j >= x + 1; j--)
//	{
//		arr[j][x] = i;
//		if (i == n * n) return;
//		i++;
//	}
//	start(arr, n, x + 1, y + 1);
//}
//用方向向量写的算法
//void direction(vector<vector<int>>& arr,int n)
//{
//	vector <int>dx = { 1,0,-1,0 };
//	vector<int>dy  = { 0,1,0,-1 };
//	int x = 0, y = 0;
//	int pos = 0;//(pos+1)%4
//				//0 1 2 3
//	for (int i = 1; i <= n * n; i++)
//	{
//		arr[y][x] = i;
//
//		int next_x=x + dx[pos]; 
//		int next_y=y + dy[pos];
//		if (next_x >= n|| next_x <0 || next_y >= n|| next_y <0 || arr[next_y][next_x] != 0)
//		{
//			pos = (pos + 1) % 4;
//		}
//		x += dx[pos];y+= dy[pos];
//	}
//}
//	
//int main()
//{
//	int n;
//	cin >> n;
//	////方法一
//	//vector<vector<int>>arr(n, vector<int>(n));
//	//start(arr, n, 0, 0);
//	//方法二
//	vector<vector<int>>arr(n, vector<int>(n));
//	direction(arr, n);
//	for (int r = 0; r < n; r++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			printf("%3d", arr[r][j]);
//		}
//		cout << endl;
//	}
//	return 0;
//}
