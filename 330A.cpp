#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x;
    cin >> x;
    if (x < 3 || x > 3 * 6)cout << "No";
    else cout << "Yes";
    return 0;
}
