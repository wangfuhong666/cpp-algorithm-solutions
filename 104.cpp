#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)if (s[i] == '1')count++;
    if (count < 2)
    {
        cout << s;
        return 0;
    }
    vector<int>pos;
    for (int i = 0; i < n; i++)if (s[i] == '1')pos.push_back(i);
    int maxk = count / 2;
    vector<int>cand;
    cand.push_back(0);
    cand.push_back(maxk);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            int k = lower_bound(pos.begin(), pos.end(), i) - pos.begin();
            if (k <= maxk)
            {
                cand.push_back(k);
                if (k > 0)cand.push_back(k - 1);
                if (k < maxk)cand.push_back(k + 1);
            }
        }
    }
    sort(cand.begin(), cand.end());
    cand.erase(unique(cand.begin(), cand.end()), cand.end());
    string ans = s;
    for (int k : cand)
    {
        string cur;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                cnt++;
                if (cnt <= k)continue;
                if (cnt > count - k)cur += '2';
                else cur += '1';
            }
            else cur += s[i];
        }
        if (cur < ans)ans = cur;
    }
    cout << ans;
    return 0;
}
