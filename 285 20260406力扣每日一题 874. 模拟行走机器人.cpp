#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int m = 6e4 + 1;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        int dx[] = { 0,1,0,-1 };
        int dy[] = { 1,0,-1,0 };
        unordered_set<int>st;
        for (auto e : obstacles) st.insert(e[0] * m + e[1]);
        int x = 0, y = 0, k = 0;
        int ans = 0;
        for (auto c : commands)
        {
            if (c == -1)k = (k + 1) % 4;
            else if (c == -2)k = (k + 3) % 4;
            else
            {
                while (c--)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (st.count(nx * m + ny))break;

                    x = nx;
                    y = ny;
                }
                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}
