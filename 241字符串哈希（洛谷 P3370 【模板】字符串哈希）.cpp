#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
ULL stringhash(string s, int p)
{
    int n = s.size();
    ULL res = 0;
    for (int i = 0; i < n; i++) res = res * p + s[i];
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ULL>arr;
    while (n--)
    {
        string s;
        cin >> s;
        arr.push_back(stringhash(s, 10));
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    cout << arr.size();
    return 0;
}
