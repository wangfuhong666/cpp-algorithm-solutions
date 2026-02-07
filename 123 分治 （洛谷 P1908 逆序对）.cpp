#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
long long test(vector<long long>&arr,int l,int r, vector<long long>&tmp)
{
    if (l >= r)return 0;
    long long ret = 0LL;
    int mid = (l + r) / 2;
    ret += test(arr, l, mid, tmp);
    ret += test(arr, mid + 1, r, tmp);
    int cur1 = l, cur2 = mid + 1, i = l;
    while (cur1 <= mid && cur2 <= r)
    {
        if (arr[cur1] <= arr[cur2])tmp[i++] = arr[cur1++];
        else
        {
            ret += mid - cur1 + 1;
            tmp[i++] = arr[cur2++];
        }
    }
    while (cur1 <= mid)tmp[i++] = arr[cur1++];
    while (cur2 <= r)tmp[i++] = arr[cur2++];
    for (int j = l; j <= r; j++)arr[j] = tmp[j];
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<long long>arr(n, 0);
    vector<long long>tmp(n+10, 0);
    for (auto& num : arr)cin >> num;
    cout << test(arr, 0, n - 1, tmp);
    return 0;
}