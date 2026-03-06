#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
//直接求字符串的哈希值（p进制下）
 ULL stringhash(string s,int p)
{
    int n = s.size();
    ULL res = 0;
    for (int i = 0; i < n; i++) res = res * p + s[i];   
    return res;
}
 //在反复要求求其子串的情况下采用此法
 const int N = 1e3 + 10;
 ULL f[N];
 ULL p[N];
 void stringhashplus(string s, int p1)
 {
     int n = s.size();
     f[0] = 0;
     p[0] = 1;
     for (int i = 1; i <= n; i++)
     {
         f[i] = f[i - 1] * p1 + s[i - 1];
         p[i] = p[i - 1] * p1;
     }
 }
 //查找字符串在[l,r]（下标从1开始计数）的哈希值
 ULL findhash(string s, int l, int r)
 {
     return f[r] - f[l - 1] * p[r - l + 1];
 }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    int p;
    cin >> s >> p;
    //cout << "字符串" << s << "在" << p << "进制下的哈希值为：" << stringhash(s, p);
    cout << stringhash("abc", p) << '\n';
    stringhashplus(s, p);
    cout << findhash(s, 2, 4) << '\n';

    return 0;
}

