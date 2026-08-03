#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n;
vector<long long>T, D, L;
vector<bool>mp(25, false);
int count1 = 0;
bool judge = false;
void dfs(long long endmin)
{
    if (count1 == n)
    {
        judge = true;
        return;
    }
    if (judge)return;
    for (int i = 0; i < n; i++)
    {
        if (mp[i])continue;
        if (endmin > T[i] + D[i])continue;
        mp[i] = true;
        count1++;
        if (endmin < T[i])dfs(T[i] + L[i]);
        else dfs(endmin + L[i]);
        mp[i] = false;
        count1--; 
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        T.clear();
        D.clear();
        L.clear();
        fill(mp.begin(), mp.end(), false);
        judge = false;
        for (int i = 0; i < n; i++)
        {
            long long c1, c2, c3;
            cin >> c1 >> c2 >> c3;
            T.push_back(c1);
            D.push_back(c2);
            L.push_back(c3);
        }
        for (int i = 0; i < n ; i++)
        {
            if (judge)break;
            mp[i] = true;
            count1 = 1;
            dfs(T[i] + L[i]);
            mp[i] = false;
           if (judge)break;
        }
        if (judge)cout << "YES" << '\n';
        else cout << "NO"<<'\n';
    }
    return 0;
}
