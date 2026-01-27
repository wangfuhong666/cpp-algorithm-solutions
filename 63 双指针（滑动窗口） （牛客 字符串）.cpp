#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	int l = 0, r = 0;
	int count = 0;
	int minlen = 0x3f3f3f3f;
	vector<int>ha(27, 0);
	while (r < n)
	{
		if (ha[s[r] - 96] == 0)count++;
		ha[s[r] - 96]++;
		while (count == 26)
		{
			while (ha[s[l] - 96] > 1)ha[s[l++] - 96]--;
			minlen = min(minlen, r - l + 1);
			ha[s[l] - 96]--;
			if (ha[s[l] - 96] == 0)count--;
			l++;

		}
		r++;
	}
	cout << minlen;
	return 0;
}