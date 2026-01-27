#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>////O(1)
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int>arr(n, 0);
		for (auto& num : arr)cin >> num;
		int l = 0,r=0;
		unordered_map<int, int>mp;
		int maxlen = 0;
		while (r < n)
		{
			mp[arr[r]]++;
			while(mp[arr[r]] > 1)
			{
				
				mp[arr[l++]]--;
			}
			r++;
			maxlen = max(r - l, maxlen);
		}
		cout << maxlen << endl;
	}
	return 0;
}