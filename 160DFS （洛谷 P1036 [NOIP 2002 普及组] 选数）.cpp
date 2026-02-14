#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n, k;
int arr[25];
int cnt = 0;
int res = 0;
int count1 = 0;
void test()
{
  
    if (cnt < 2) return;
    for (int i = 2; i<=cnt/i; i++)if (cnt % i == 0)return;
    count1++;
}

void dfs(int begin)
{
    if (res == k)
    {
        test();
        return;
    }
    if ((n - begin) < (k - res)) return;
    for (long long i = begin; i < n; i++)
    {
        cnt += arr[i];
        res++;
        dfs(i+1);
        cnt -= arr[i];
        res--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; i++)cin >> arr[i];
    dfs(0);
    cout << count1;
    return 0;
}
