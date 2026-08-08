#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

void sol()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<string>> a(n);
    for(int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        string word;
        for(int j = 0; j <= (int)s.size(); j++)
        {
            if(j == (int)s.size() || s[j] == ' ')
            {
                a[i].push_back(word);
                word.clear();
            }
            else word += s[j];
            
        }
    }

    vector<int> pos(n, 0);
    vector<string> cur(n);
    vector<bool> vis(n, false);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (int)a[i].size(); j++)
        {
            cur[i] += a[i][j][0];
        }
    }

    while(true)
    {
        unordered_map<string, int> mp;

        for(int i = 0; i < n; i++)
        {
            mp[cur[i]]++;
        }

        vector<int> cnt;

        for(int i = 0; i < n; i++)
        {
            if(vis[i])
                continue;

            if(mp[cur[i]] == 1)vis[i] = true;     
            else cnt.push_back(i);
            
        }
        if(cnt.empty())break;
        for(auto id : cnt)
        {
            pos[id]++;
            string s;
            for(int j = 0; j < (int)a[id].size(); j++)
            {
                if(j < pos[id]) s += a[id][j];      
                else s += a[id][j][0];        
            }

            cur[id] = s;
        }
    }

    for(int i = 0; i < n; i++) cout << cur[i] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) sol();

    return 0;
}