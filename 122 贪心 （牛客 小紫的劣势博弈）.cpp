#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long>arr(n, 0);
    for (auto& num : arr)cin >> num;
    sort(arr.begin(), arr.end());
    long long x = 0LL;
    int j = 1;
    for (int i = 0; i < n; i++)
    {
        x += arr[i] * j;
        j *= -1;
    }
    cout << x;
    return 0;
}