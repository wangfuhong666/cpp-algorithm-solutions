#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;
void dfs(int n, char x, char z, char y)
{
	if (n < 1)return;
	dfs(n - 1, x, y, z);
	printf("%c->%d->%c\n", x, n, z);
	dfs(n - 1, y, z, x);
}
int main()
{
	int n;
	char a, b, c;
	cin >> n>>a>>b>>c;
	dfs(n, a, b, c);
	return 0;
}