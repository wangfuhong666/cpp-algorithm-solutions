#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
bool isprime(int x)
{
    if (x < 2)return false;
    for (int i = 2; i <= x / i; i++)if (x %i== 0)return false;
    return true;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    FILE* P = freopen("prime.txt", "w", stdout);
    int cnt = 0;
    int res = 0;
    for (int i = 1; i < 1e6; i++)
    {
        if (isprime(i))
        {
            cnt++;
            res++;
            cout << cnt << ' ' << i <<"    ";
            if (res % 10 == 0)cout << '\n';
        }
    }
    return 0;
}
