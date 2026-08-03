#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
using PII = pair<int, int>;
bool cmp1(PII a, PII b)
{
	return a.second < b.second;
}
bool cmp2(PII a, PII b)
{
	return a.first < b.first;
}
int main()
{
	int C,L;
	cin >> C >> L;
	vector<PII>arr1(C);
	vector<PII>arr2(L);
	for (auto &num : arr1)cin >> num.first >> num.second;
	for (auto &num : arr2)cin >> num.first >> num.second;
	sort(arr1.begin(), arr1.end(), cmp1);
	sort(arr2.begin(), arr2.end(), cmp2);
	int res = 0;
	
	for (int i = 0; i < C; i++)
	{
		int min = arr1[i].first;
		int max = arr1[i].second;
		
		for (int j = 0; j < L; j++)
		{		
			int spf = arr2[j].first;
			if ( spf<min || arr2[j].second <= 0)continue;
			if (spf > max)break;

			res++;
			arr2[j].second--;
			break;
		}
	}

	cout << res;
	return 0;
}