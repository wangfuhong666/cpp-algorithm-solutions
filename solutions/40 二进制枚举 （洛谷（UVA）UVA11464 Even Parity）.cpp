#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int getsum(vector<vector<int>>& arr, int y, int x)
{
	vector<int>dx{ -1,1,0,0 };
	vector<int>dy{ 0,0,1,-1 };
	int tem = 0;
	for (int i = 0; i < 4; i++)
	{
		tem += arr[y + dy[i]][x + dx[i]];
	}
	return tem;
}
void start_sum(vector<vector<int>>& arr, vector<vector<int>>& sum,int n)
{

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			sum[i][j]=getsum(arr, i, j);
		}
	}	
}
void change_sum(vector<vector<int>>& sum, int y, int x)
{
	vector<int>dx{ -1,1,0,0 };
	vector<int>dy{ 0,0,1,-1 };
	for (int i = 0; i < 4; i++)
	{
		sum[y + dy[i]][x + dx[i]] += 1;
	}
}
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int n;
		cin >> n;
		vector<vector<int>>arr(n + 2, vector<int>(n + 2));
		vector<vector<int>>sum(n + 2, vector<int>(n + 2));
		for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)cin >> arr[i][j];
		start_sum(arr, sum, n);
		vector<int>total;
		for (int st = 0; st < (1 << n); st++)
		{
			bool judge = true;
			vector<vector<int>>arr1 = arr;
			vector<vector<int>>sum1 = sum;
			int count = 0;
			for (int i = 0; i < n; i++)
			{
				int m = i + 1;
				if (((st >> i) & 1)&&arr1[1][m]==0)
				{
					count++;
					arr1[1][m] = 1;
					change_sum(sum1, 1, m);
				}
			}
			for (int i = 2; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (sum1[i - 1][j] % 2 == 1)
					{
						if (arr1[i][j] == 0)
						{
							count++;
							arr1[i][j] = 1;
							change_sum(sum1, i, j);
						}
						else
						{
							judge = false;
							break;
						}
					}
					
				}
				if (!judge)break;
			}
			for (int i = 1; i <= n; i++)
			{
				if (!judge)break;
				for (int j = 1; j <= n; j++)
				{
					if (sum1[i][1] % 2 == 1)
					{
						judge = false;
						break;
					}
				}
			}
			if (!judge)total.push_back(10000);
			else total.push_back(count);
			
			

		}
		sort(total.begin(), total.end());
		cout << "Case " << t << ": ";
		if (total[0] == 10000)cout << -1 << endl;
		else cout << total[0] << endl;
		
		
	}
	return 0;
}