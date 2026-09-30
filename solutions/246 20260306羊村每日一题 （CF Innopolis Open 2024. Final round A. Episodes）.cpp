#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int idx;
	long long v;
	long long t;
};
bool cmp(node& a, node& b)
{
	return a.t < b.t;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	//栈 堆                                                     
	vector<node>arr(n);
	long long sumv = 0LL;
	for (int i = 0; i < n; i++)
	{
		long long v, t;
		cin >> v >> t;
		sumv += v;
		arr[i] = { i,v,t };
	}
	sort(arr.begin(), arr.end(), cmp);
	         
	long long curv = sumv;
	long long curt = 0LL;
	long double res = 0.0;
	for (int i = 0; i < n; i++)
	{
		int idx = arr[i].idx;
		long long v = arr[i].v;
		long long t = arr[i].t;
		res += (long double)(t-curt) * curv / (long double)sumv;
		ans[idx] = res;
		curv -= v;
		curt = t;
	}
	for (auto num : ans)cout << fixed << setprecision(15)<<num << "\n";
	return 0;
}