#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
//质因数分解（x>=2）
vector<PII>facter(int x)
{
    vector<PII>res;
    for (int i = 2; i <= x / i; i++)
    {
        
        if(x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                cnt++;
                x /= i;
            }
            res.emplace_back(i, cnt);

        }
    }
    if (x > 1)res.emplace_back(x, 1);
    return res;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<PII>res = facter(n);
    int count = 0;
    cout << n << "的质因数分解结果为";
    for (auto [a, b] : res)
    {
        count++;
        if (count != 1)cout << '*';
        cout << a << '^' << b;
    }
    return 0;
}