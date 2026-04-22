#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int minLength(vector<int>& nums, int k)
{
        unordered_map<int, int>mp;
        int l = 0, r = 0;
        int n = nums.size();
        long long sum = 0LL;
        int len = 0, minlen = 0x3f3f3f3f;
        while (r < n)
        {
            if (mp[nums[r]] == 0) sum += nums[r];       
            mp[nums[r]]++;
            while (sum >= k)
            {
                minlen = min(minlen, r - l + 1);
                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                {
                    sum -= nums[l];
                }
                l++;
            }
            r++;
        }
        if (minlen == 0x3f3f3f3f)return -1;
        else return minlen;
}
int main()
{

}
