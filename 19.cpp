#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//错误思路
int main()
{
	long long n, m,F;
	cin >> n >> m;
	long long res = m % n;
	if (res > 0)
	{
		F = m / n + 1;
		res--;
	}
	else
	{
		F = m / n;
	}
	
	for (long long i = 0LL; i < n-1; i++)
	{
		long long cer;
		if (res > 0)
		{
			cer= m / n + 1;
			res--;
		}
		else
		{
			cer= m / n;
		}
		F &= cer;
	}
	cout << F;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
using namespace std;
//不知道对不对
int main()
{

	
		auto B = clock();
		long long n, m, F;
		cin >> n >> m;
		F = m / n;

		for (long long i = 0LL; i < n - 1; i++)
		{
			long long cer;
			cer = m / n;
			F &= cer;
		}
		auto S = clock();
		cout << F<<endl<<"总用时: "<<S-B<<"ms"<<endl;
		
	
	return 0;
}
正确思路
贪心


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
using namespace std;
int main()
{
		{
		}
	return 0;
}
