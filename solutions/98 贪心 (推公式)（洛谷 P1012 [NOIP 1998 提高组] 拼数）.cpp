#include<bits/stdc++.h>

using namespace std;
bool cmp(string a, string b)
{
	return a + b > b + a;
}
int main()
{
	int n;
	cin >> n;
	vector<string>arr(n);
	for (auto& s : arr)cin >> s;
	sort(arr.begin(), arr.end(), cmp);
	for (auto& s : arr)cout<< s;
	return 0;
}