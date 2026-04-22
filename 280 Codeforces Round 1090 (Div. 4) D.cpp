#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<long long> arr;
bool vis[N];
void start() 
{
    fill((bool*)vis, (bool*)vis + N, true);
    vis[0] = false;
    vis[1] = false;
    for (int p = 2; p < N; p++) 
    {
        if (vis[p]) 
        {
            arr.push_back(p);
            if (arr.size() > 1e5+1e4+10) break;
            for (long long i = (long long)p * p; i < N; i += p)vis[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    start();
    int T;
    cin >> T;
    while (T--) 
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)cout << arr[i] * arr[i + 1] << (i == n - 1 ? "" : " ");
        cout << "\n";
    }
    return 0;
}
