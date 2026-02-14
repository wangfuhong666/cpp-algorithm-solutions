#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
struct p
{
    long long w, c;
    bool operator>(const p&othor)const
    {
        return w > othor.w;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    map<long long, long long > count;
    
    for (int i = 0; i < n; i++)
    {
        long long c, w;
        cin >> c >> w;
        count[w] += c;
    }
    priority_queue<p, vector<p>, greater<p>>q;
    for (auto [w, c] : count)
    {
        q.push({ w,c });
    }
    long long sum = 0LL;
    while (!q.empty())
    {
        p cur = q.top();
        q.pop();
        if (cur.c >= 2)
        {
            long long tem1 = cur.c / 2;
            long long tem2 = cur.w * 2;
            long long tmp = (tem1 % mod) * (tem2 % mod) % mod;
            sum = (sum + tmp) % mod;
            q.push({ tem2,tem1 });
            cur.c %= 2;
        }
        if (cur.c == 1)
        {
            if (q.empty())break;
            p next = q.top();
            q.pop();
            long long new1 = cur.w + next.w;
            sum = (sum + (new1 % mod)) % mod;
            q.push({ new1,1 });
            if (next.c > 1)q.push({ next.w,next.c - 1 });
        }
    }
    cout << sum;
    return 0;
}
