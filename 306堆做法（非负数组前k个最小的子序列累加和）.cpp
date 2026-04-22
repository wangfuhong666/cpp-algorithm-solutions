#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
using PLI = pair<long long, int>;
// ==========================================
// 1. 你的优化算法 (请把你的代码填在这里)
// ==========================================
vector<long long> topKSumOptimized(vector<int> nums, int k) 
{
    // 这里填入你写的 O(NlogN + KlogK) 的代码
    // 示例逻辑（仅供占位）：
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<long long> ans;
    priority_queue<PLI, vector<PLI>, greater<PLI>>pq;
    if (k == 1)return { 0 };
    pq.emplace(nums[0], 0);
    ans.push_back(0);
    while (ans.size() < k&&!pq.empty())
    {
        auto [a, b] = pq.top();
        pq.pop();
        ans.push_back(a);
        if (b + 1 >= n)continue;
        pq.emplace(a - nums[b] + nums[b + 1], b + 1);
        pq.emplace(a + nums[b + 1], b + 1);
    }
    return ans;

}

// ==========================================
// 2. 暴力解法 (用于验证，保证绝对正确)
// ==========================================
void dfs(int i, long long sum, const vector<int>& nums, vector<long long>& allSums) {
    if (i == nums.size()) {
        allSums.push_back(sum);
        return;
    }
    dfs(i + 1, sum, nums, allSums);           // 不选
    dfs(i + 1, sum + nums[i], nums, allSums); // 选
}

vector<long long> topKSumBruteForce(vector<int> nums, int k) {
    vector<long long> allSums;
    dfs(0, 0, nums, allSums);
    sort(allSums.begin(), allSums.end());

    vector<long long> res;
    for (int i = 0; i < min((int)allSums.size(), k); ++i) {
        res.push_back(allSums[i]);
    }
    return res;
}

// ==========================================
// 3. 对数器逻辑
// ==========================================
vector<int> generateRandomArray(int n, int maxVal) {
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = rand() % maxVal + 1; // 生成1~maxVal的随机数
    }
    return res;
}

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    srand(time(NULL));
    int testTimes = 50000; // 测试次数
    int maxN = 15;        // 暴力解法复杂度高，N不能太大
    int maxVal = 100;     // 数组元素最大值

    cout << "开始测试..." << endl;
    for (int i = 0; i < testTimes; i++) 
    {
        int n = rand() % maxN + 1;
        int k = rand() % (1 << n) + 1; // K 不能超过 2^n
        if (k > 100) k = 100;          // 限制一下K的大小方便观察

        vector<int> nums = generateRandomArray(n, maxVal);

        vector<long long> ans1 = topKSumBruteForce(nums, k);
        vector<long long> ans2 = topKSumOptimized(nums, k);

        // 比对结果
        bool match = true;
        if (ans1.size() != ans2.size()) 
        {
            match = false;
        }
        else {
            for (int j = 0; j < ans1.size(); j++) 
            {
                if (ans1[j] != ans2[j]) {
                    match = false;
                    break;
                }
            }
        }

        if (!match) {
            cout << "出错了！" << endl;
            cout << "输入数组: "; printArray(nums);
            cout << "K: " << k << endl;
            cout << "正确结果: "; for (auto x : ans1) cout << x << " "; cout << endl;
            cout << "你的结果: "; for (auto x : ans2) cout << x << " "; cout << endl;
            return 0;
        }
    }
    cout << "测试通过！" << endl;
    return 0;
}