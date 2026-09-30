#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int minSwaps(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<int>arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            int l = n - 1, r = n - 1;
            while (l >= 0 && grid[i][l] == 0)l--;
            arr[i] = r - l;
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= n - 1 - i)continue;
            int pos = -1;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] >= n - 1 - i)
                {
                    pos = j;
                    int tem = arr[j];
                    for (int k = j; k > i; k--)arr[k] = arr[k - 1];
                    arr[i] = tem;
                    count += j - i;
                    break;
                }
            }
            if (pos == -1)return -1;
        }

        return count;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>>arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)cin >> arr[i][j];
    }
    cout << Solution::minSwaps(arr);
    return 0;
}
