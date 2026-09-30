#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n, k;
int res = 0;
int sum = 0;
void dfs(int pos, int num)
{
    if (pos > k)
    {
        if (sum == n)res++;
        return;
    }
    for (int i = num; i <= n; i++)
    {     
        if (n-sum < (k-pos+1)*i)break;
        sum += i;
        dfs(pos+1,i);
        sum -= i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    n = k = res = sum = 0;
    cin >> n >> k;
    dfs(1, 1);
    cout << res;
    return 0;
}
