#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string s;
	cin >> s;
	long long dpa = 0, dpb = 0, dpc = 0;

	for (char ch : s) 
	{
		if (ch == 'a') dpa = (dpa + dpb + dpc + 1) % mod;
		else if (ch == 'b') dpb = (dpb + dpa + dpc + 1) % mod;		
		else if (ch == 'c') dpc = (dpc + dpa + dpb + 1) % mod;
		
	}
	cout << (dpa + dpb + dpc) % mod;
	return 0;
}
