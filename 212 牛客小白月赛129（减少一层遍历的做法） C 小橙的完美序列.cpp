#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
//通过优化的方式省下了第二次遍历
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<int, int>mp;
    int res = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int tem;
        cin >> tem;
        int x = tem ^ i;
        res=max(res,++mp[x]);
    }
    
    cout << n - res;
    return 0;
}
