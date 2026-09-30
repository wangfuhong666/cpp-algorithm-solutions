#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
long long getrand(vector<long long>& arr, int l, int r)
{
	
	return arr[rand() % (r - l + 1) + l];
}
long long quick_select(vector<long long>& arr, int l, int r, int k)
{
	if (l >= r)return arr[l];;
	int p = getrand(arr, l, r);
	int ll = l - 1, i = l, rr = r + 1;
	while (i < rr)
	{
		if (arr[i] < p)swap(arr[++ll], arr[i++]);
		else if (arr[i] == p)i++;
		else swap(arr[--rr], arr[i]);
	}
	int c1 = ll - l + 1, c2 = rr - 1 - ll,c3 = r - rr + 1;
	if (k < c1) return quick_select(arr, l, ll, k);
	else if (k < c1 + c2)return p;
	else return quick_select(arr, rr, r, k-c1-c2);

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	srand(time(nullptr));
	long long n, k;
	cin >> n >> k;
	vector<long long>arr(n);
	for (auto& num : arr)cin >> num;
	cout << quick_select(arr, 0, n - 1, k);
	return 0;
}