#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
using ll = long long;
vector<bool>isprime(N, true);
vector<int>prime;

void getprime(int n)
{
    isprime[0] = isprime[1] = false;
    for (ll i = 2; i <= n; i++)
    {
        if (isprime[i])prime.push_back(i);
        //for(int i=0;i<;)
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}
