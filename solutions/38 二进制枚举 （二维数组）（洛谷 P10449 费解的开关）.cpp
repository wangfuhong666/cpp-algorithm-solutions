#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
////fopen fwrite fclose
//0-->1 1-->0(i+1)%'0'
void tesk(vector<vector<int>>& arr, int y,int x )
{
	vector<int>dx = { 0,0,0,-1,1 };
	vector<int>dy = { 0,-1,1,0,0 };
	for (int i = 0; i < 5; i++)arr[y + dy[i]][x + dx[i]] = (arr[y + dy[i]][x + dx[i]] + 1) % 2;
}
	

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		vector<vector<int>>arr(7, vector<int>(7));
		for (int i = 1; i <= 5; i++)
		{
			for (int j = 1; j <= 5; j++)
			{
				char ch;
				cin >> ch;
				arr[i][j]=ch-'0';
			}
		}
		vector<int>sum;
		for (int st = 0; st < (1 << 5); st++)
		{
			vector<vector<int>>arr1 = arr;
			int count = 0;
			for (int i = 0; i < 5; i++)
			{
				if ((st >> i) & 1)
				{
					count++;
					tesk(arr1, 1, i+1);
				}
			}
			for (int i = 2; i <= 5; i++)
			{
				for (int j = 1; j <= 5; j++)
				{
					if (arr1[i - 1][j] == 0)
					{
						count++;
						tesk(arr1, i, j);
					}
						
				}
			}
			bool judge = true;
			for (int i = 1; i <= 5; i++)
			{
				for (int j = 1; j <= 5; j++)
				{
					if (arr1[i][j] == 0)
					{
						judge = false;
						sum.push_back(1000);
						break;
					}
				}
				if (!judge)break;
			}
			if(judge)sum.push_back(count);

		}
		sort(sum.begin(), sum.end());
		if (sum[0] > 6)cout << -1<<endl;
		else cout << sum[0]<<endl;

	}
	return 0;
}