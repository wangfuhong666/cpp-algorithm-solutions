#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>aa(n);
	vector<int>bb(n);
	vector<int>xx(n);
	vector<int>yy(n);
	for (int i = 0; i < n; i++)cin >> aa[i] >> bb[i] >> xx[i] >> yy[i];
	int x, y;
	cin >> x >> y;
	bool judge = true;
	for (int i = n-1; i >= 0; i--)
	{
		if (x >= aa[i] && x <= aa[i] + xx[i] && y >= bb[i] && y <= bb[i] + yy[i])
		{
			judge = false;
			cout << i + 1;
			break;
		}
	}
	if (judge)cout << -1;

	
	return 0;
}