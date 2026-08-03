#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long xa, ya, xb, yb;
	cin >> xa >> ya >> xb >> yb;
	long long tem = xa * yb - xb * ya;
	if (ya == yb)
	{
		if (tem == 4LL || tem == -4LL)printf("%.10lf\n", 0.0);
		else cout << "no answer" << '\n';
	}
	else
	{
		double x = (double)(4.0 - tem) / (ya - yb);
		printf("%.10lf\n", x);
	}

	return 0;
}