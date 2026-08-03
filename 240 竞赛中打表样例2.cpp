#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<unsigned long long>arr(21, 1);
    freopen("fac.txt", "w", stdout);
    for (int i = 1; i <= 20; i++)
    {
        arr[i] = arr[i - 1] * i;
        cout <<i<<"!=" << arr[i] << "   ";
    }
    
    return 0;
}
