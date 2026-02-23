#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
bool cmp(vector<int>& a, vector<int>& b)
{
	return a[2] < b[2];
}
const int N = 1e5 + 10;
int fa[N];
void start(int n)
{
	for (int i = 0; i < n; i++)fa[i] = i;
}
int find(int x)
{
	if (fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
void un(int x, int y)
{
	int fx = find(x);
	int fy = find(y);

	if (fx != fy) fa[fx] = fy;
}
bool issameset(int x, int y)
{
	return find(x) == find(y);
}


vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson)
{
	sort(meetings.begin(), meetings.end(), cmp);
	start(n);
	un(0, firstPerson);
	int l = 0, r = 0;
	while (r < meetings.size())
	{
		vector<int>tem;
		while ((r < meetings.size() && meetings[l][2] == meetings[r][2]))
		{
			int x = meetings[r][0];
			int y = meetings[r][1];
			un(x, y);
			tem.push_back(x);
			tem.push_back(y);
			r++;
		}
		for (auto num : tem)if (!issameset(num, 0))fa[num] = num;
		l = r;
	}
	vector<int>res;
	for (int i = 0; i < n; i++)if (issameset(i, 0))res.push_back(i);
	return res;

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, firstperson, m;
	cin >> n >> firstperson >> m;
	vector<vector<int>>arr;
	for (int i = 0; i < m; i++)
	{
		vector<int>tem(3);
		cin >> tem[0] >> tem[1] >> tem[2];
		arr.push_back(tem);
	}
	vector<int>res = findAllPeople(n, arr, firstperson);
	for (auto num : res)cout << num << ' ';
	return 0;
}
