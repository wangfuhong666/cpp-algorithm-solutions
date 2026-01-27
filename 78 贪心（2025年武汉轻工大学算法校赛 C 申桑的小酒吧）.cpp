#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<long long>arr1(5, 0);
	vector<int>arr2{ 5,10,20,50,100 };
	int n;
	cin >> n;
	bool judge = true;
	for (int i = 0; i < n; i++)
	{
		int c1, c2;
		cin >> c1 >> c2;
		auto it = lower_bound(arr2.begin(), arr2.end(), c2);
		arr1[it - arr2.begin()]++;
		int cnt = c2 - c1*5;
		if (cnt == 0)continue;
		if (!judge)continue;
		for (int j = 4; j >= 0; j--)
		{
			if (arr2[j] > cnt)continue;
			int cnttem = cnt / arr2[j];
			if (arr1[j] < cnttem)
			{
				cnt -= arr1[j] * arr2[j];
				arr1[j] = 0;
				continue;
			}
			cnt -= cnttem * arr2[j];
			arr1[j] -= cnttem;
		}
		if (cnt > 0)judge = false;
	}
	if (judge)cout << "true";
	else cout << "false";
	return 0;
}