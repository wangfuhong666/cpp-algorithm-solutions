#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}
//纯暴力暴力
vector<int> arr;
int ans;
int dfs(int idx, int sum)
{
    if (idx == arr.size() - 1)return (sum == ans ? 1 : 0);
    return dfs(idx + 1, sum + arr[idx + 1]) + dfs(idx + 1, sum - arr[idx + 1]);
}
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        arr = nums;
        ans = target;
        return dfs(-1, 0);
    }
};
//记忆化搜索（哈希表数组（why:sum可能为负值））
vector<int> arr;
int ans;
vector<unordered_map<int, int>>mp;
int dfs(int idx, int sum)
{
    if (idx == arr.size() - 1)
    {
        mp[idx][sum] = (sum == ans ? 1 : 0);
        return (sum == ans ? 1 : 0);
    }
    int tem1;
    if (mp[idx + 1].count(sum + arr[idx + 1]))tem1 = mp[idx + 1][sum + arr[idx + 1]];
    else
    {

        tem1 = dfs(idx + 1, sum + arr[idx + 1]);
        mp[idx + 1][sum + arr[idx + 1]] = tem1;

    }
    int tem2;
    if (mp[idx + 1].count(sum - arr[idx + 1]))tem2 = mp[idx + 1][sum - arr[idx + 1]];
    else
    {

        tem2 = dfs(idx + 1, sum - arr[idx + 1]);
        mp[idx + 1][sum - arr[idx + 1]] = tem2;

    }
    return tem1 + tem2;
}
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        arr = nums;
        ans = target;
        mp.clear();
        mp.resize(nums.size());
        return dfs(-1, 0);
    }
};
//经过偏移处理的记忆化搜索（为了去掉哈希表）
vector<int> arr;
int ans;
vector<vector<int>>dp;
int s;
int dfs(int idx, int sum)
{
    if (idx == arr.size() - 1)
    {
        dp[idx][sum + s] = (sum + s == ans ? 1 : 0);
        return (sum + s == ans ? 1 : 0);
    }
    int tem1;
    if (dp[idx + 1][sum + s + arr[idx + 1]] != -1)tem1 = dp[idx + 1][sum + s + arr[idx + 1]];
    else
    {

        tem1 = dfs(idx + 1, sum + arr[idx + 1]);
        dp[idx + 1][sum + s + arr[idx + 1]] = tem1;

    }
    int tem2;
    if (dp[idx + 1][sum + s - arr[idx + 1]] != -1)tem2 = dp[idx + 1][sum + s - arr[idx + 1]];
    else
    {

        tem2 = dfs(idx + 1, sum - arr[idx + 1]);
        dp[idx + 1][sum + s - arr[idx + 1]] = tem2;

    }
    return tem1 + tem2;
}
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        arr = nums;

        for (auto num : nums)s += abs(num);
        ans = target + s;
        dp.assign(arr.size(), vector<int>(ans + s + 1, -1));
        return dfs(-1, 0);
    }
};
//偏移化的迭代形式
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        for (int x : nums) s += abs(x);
        if (abs(target) > s) return 0;
        vector<vector<int>> dp(n, vector<int>(2 * s + 1, 0));
        dp[0][s + nums[0]] += 1;
        dp[0][s - nums[0]] += 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= 2 * s; j++)
            {
                if (dp[i - 1][j] > 0)
                {
                    if (j + nums[i] <= 2 * s)
                    {
                        dp[i][j + nums[i]] += dp[i - 1][j];
                    }
                    if (j - nums[i] >= 0)
                    {
                        dp[i][j - nums[i]] += dp[i - 1][j];
                    }
                }
            }
        }

        return dp[n - 1][s + target];
    }
};
//转化为01背包问题
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        for (int& x : nums)
        {
            s += abs(x);
            x = abs(x);
        }
        if (abs(target) > s || (target % 2 != s % 2)) return 0;
        int w = (long long)(s + abs(target)) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                dp[i + 1][j] = dp[i][j];
                if (j >= nums[i])dp[i + 1][j] += dp[i][j - nums[i]];
            }
        }
        return dp[n][w];
    }
};
//空间优化
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        for (int& x : nums)
        {
            s += abs(x);
            x = abs(x);
        }
        if (abs(target) > s || (target % 2 != s % 2)) return 0;
        int w = (long long)(s + abs(target)) / 2;
        vector<int> dp(w + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j=w; j >= nums[i];j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[w];
    }
};