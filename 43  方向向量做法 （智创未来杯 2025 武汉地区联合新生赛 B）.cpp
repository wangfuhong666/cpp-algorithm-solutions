#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>//sort upper_bound 
using namespace std;
void around(vector<vector<int>>& arr, vector<int>& y, vector<int>& x,int&mn)
{
	vector<int>dx{-1,0,1,-1,1,-1,0,1};
	vector<int>dy{-1,-1,-1,0,0,1,1,1 };
	int n = arr.size();
	int m = arr[0].size();
	for (int i = 0; i < x.size(); i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int xx = x[i] + dx[j];
			int yy = y[i] + dy[j];
			if (xx < 0 || xx >= m || yy < 0 || yy >= n || arr[yy][xx] != 0)continue;
			arr[yy][xx] = mn--;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>arr(n, vector<int>(m));
		if (k == 0)
		{
			cout << "Yes" << endl;
			int mnm = 1;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					cout << mnm++;
					if (j < m - 1)cout << ' ';
				}
				cout << endl;
			}
			continue;
		}
		if (m < 3 || n < 3)
		{
			cout << "No" << endl;
			continue;
		}

		int inner_rows = n - 2;
		int inner_cols = m - 2;
		int max_k = ((inner_rows + 1) / 2) * ((inner_cols + 1) / 2);
		if (k > max_k)
		{
			cout << "No" << endl;
			continue;
		}
	
		vector<int>x;
		vector<int>y;
		for (int i = 1; i < n - 1 && x.size() < k; i += 2)
		{
			for (int j = 1; j < m - 1 && x.size() < k; j += 2)
			{
				x.push_back(j);
				y.push_back(i);
			}
		}

		int mn = m * n;
		for (int i = 0; i < x.size(); i++)arr[y[i]][x[i]] = mn--;
		around(arr, y, x, mn);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 0)arr[i][j] = ++sum;
			}
		}
		cout << "Yes" << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << arr[i][j];
				if (j < m - 1)cout << ' ';
			}
			cout << endl;
				
		}		
	}
	return 0;
}