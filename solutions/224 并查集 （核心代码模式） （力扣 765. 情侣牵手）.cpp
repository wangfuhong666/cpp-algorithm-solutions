#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 3e2 + 10;
int fa[N];
int setnum;
void start(int n)
{
	for (int i = 0; i < n; i++)fa[i] = i;
	setnum = n;
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
	if (fx != fy)
	{
		fa[fx] = fy;
		setnum--;
	}
}
bool issameset(int x, int y)
{
	return find(x) == find(y);
}

int minSwapsCouples(vector<int>& row)
{
	int n = row.size();
	int tot = n / 2;
	start(tot);
	for (int i = 0; i < n; i += 2)
	{
		un(row[i] / 2, row[i + 1] / 2);
	}
	return n / 2 - setnum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int>arr(n);
	for (auto& num : arr)cin >> num;
	cout << minSwapsCouples(arr);
	return 0;
}
