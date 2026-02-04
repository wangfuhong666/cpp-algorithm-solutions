#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

vector <int>countnum(14, 4);
vector<int>tem(14, 0);
void test(vector<vector<int>>& arr, int num)
{
	if (num == 13)return;
	tem[num]++;
	int t = arr[num][countnum[num]];
	countnum[num]--;
	test(arr, t);

}
int main()
{
	vector<vector<int>>arr(14, vector<int>(5));
	for (int i = 1; i <= 13; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			char x;
			cin >> x;
			if (x == 'A')arr[i][j] = 1;
			else if (x == 'J')arr[i][j] = 11;
			else if (x == 'Q')arr[i][j] = 12;
			else if (x == 'K')arr[i][j] = 13;
			else if (x == '0')arr[i][j] = 10;
			else arr[i][j] = x - '0';
		}
	}
	for (int i = 1; i <= 4; i++)
	{

		test(arr, arr[13][i]);

	}
	int ret = 0;
	for (auto num : tem)if (num == 4)ret++;
	cout << ret;
	return 0;
}