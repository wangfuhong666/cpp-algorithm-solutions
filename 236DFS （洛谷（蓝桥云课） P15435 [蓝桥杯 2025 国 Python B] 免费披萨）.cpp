#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
int arr[] = { 1,2,3,4,5,6,7,8 };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int maxn = 0;
    long long pos = LLONG_MAX;
    do
    {
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                long long tem = 0;
                for (int k = 0; k < j; k++)tem = tem * 10 + arr[k];
                tem = tem * 10 + i;
                for (int k = j; k < 8; k++)tem = tem * 10 + arr[k];
                long long cnt = gcd(tem, n);

                if (cnt > maxn) 
                {
                    maxn = cnt;
                    pos = tem; 
                }
                else if (cnt == maxn) 
                {
                    pos = min(pos, tem); 
                }
                
            }
        }
    } while (next_permutation(arr , arr + 8));
    cout << pos;
    return 0;
}
