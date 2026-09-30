#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
struct p
{
    int val;
    int idx;
};
bool cmp(p x, p y)
{
    return x.val < y.val;
}
int solve(vector<int>& nums, int op)
{
    int n = nums.size();
    vector<vector<int>>adj(n);
    for (int i = 0; i < n; i++)
    {
        if (op == 0)
        {
            if (abs(nums[i]) % 2 == i % 2)
            {
                adj[i].push_back(nums[i]);
            }
            else
            {
                adj[i].push_back(nums[i] + 1);
                adj[i].push_back(nums[i] - 1);
            }
        }
        else
        {
            if (abs(nums[i]) % 2 == (i + 1) % 2)
            {
                adj[i].push_back(nums[i]);
            }
            else
            {
                adj[i].push_back(nums[i] + 1);
                adj[i].push_back(nums[i] - 1);
            }
        }
    }
    vector<p>arr;
    for (int i = 0; i < n; i++)
    {
        for (auto num : adj[i])
        {
            arr.push_back({ num,i });
        }
    }
    sort(arr.begin(), arr.end(), cmp);
    int l = 0, r = 0;
    vector<int> tem(n, 0);
    int res = INT_MAX;
    int count = 0;
    while (r < arr.size())
    {
        if (tem[arr[r].idx] == 0)count++;
        tem[arr[r].idx]++;
        while (count == n)
        {
            res = min(res, arr[r].val - arr[l].val);
            tem[arr[l].idx]--;
            if (tem[arr[l].idx] == 0)count--;
            l++;
        }

        r++;
    }
    return res;
}
class Solution {
public:

    vector<int> makeParityAlternating(vector<int>& arr)
    {
        //0 1 2 34    n-1

        int n = arr.size();
        int op1 = 0, op2 = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i % 2 == 0)
            {
                if (abs(arr[i]) % 2 == 0)op1++;
                else op2++;
            }
            else
            {
                if (abs(arr[i]) % 2 == 1)op1++;
                else op2++;
            }
        }
        int ans = min(n - op1, n - op2);
        int t1 = INT_MAX, t2 = INT_MAX;
        if (ans == n - op1)t1 = solve(arr, 0);
        if (ans == n - op2)t2 = solve(arr, 1);
        return { ans,min(t1,t2) };
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>arr(n);
    for (auto& num : arr)cin >> num;
    Solution a;
    vector<int>res = a.makeParityAlternating(arr);
    cout << res[0] << ' ' << res[1];
    return 0;
}
