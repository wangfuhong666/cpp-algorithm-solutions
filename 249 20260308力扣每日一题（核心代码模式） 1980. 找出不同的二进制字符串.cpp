#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   static string findDifferentBinaryString(vector<string>& nums)
    {
        int n = nums.size();
        vector<int>arr;
        for (auto e : nums)arr.push_back(stoi(e, nullptr, 2));
        sort(arr.begin(), arr.end());
        int x = -1;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i + 1] != arr[i] + 1)
            {
                x = arr[i] + 1;
                break;
            }
        }
        if (x != -1)return bitset<16>(x).to_string().substr(16 - n, 16);
        return bitset<16>(arr[n - 1] + 1).to_string().substr(16 - n, 16);
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string>nums(n);
    for (auto& num : nums)cin >> num;
    cout << Solution::findDifferentBinaryString(nums);
    return 0;
}
