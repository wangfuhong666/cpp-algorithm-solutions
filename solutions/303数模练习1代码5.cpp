#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

struct node {
    int idx;
    int n;
};

bool check_by_sum(int sum, int path) 
{
    int tem = 5668;
    if (sum < tem) return false;
    if (10 * tem >= 8 * sum && 100 * tem <= path * sum) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("问题1input.txt", "r", stdin);
    freopen("统计结果.txt", "w", stdout); 

    vector<node> arr(45);
    int sumseat = 0;
    for (int i = 0; i < 45; i++) {
        cin >> arr[i].n;
        arr[i].idx = i + 1;
        sumseat += arr[i].n;
    }
    for (int i = 0; i < 45; i++) {
        int dummy_w;
        cin >> dummy_w;
    }

    vector<long long> count_dp(sumseat + 1, 0);
    count_dp[0] = 1; 

    for (int i = 0; i < 45; i++) {
        int n_i = arr[i].n;
        for (int s = sumseat; s >= n_i; s--) {
            count_dp[s] += count_dp[s - n_i];
        }
    }

    for (int path = 90; path <= 100; path++)
    {
        long long total_schemes = 0;

        for (int s = 5668; s <= sumseat; s++) 
        {
            if (check_by_sum(s, path))
            {
                total_schemes += count_dp[s];
            }
        }

        cout << "满座率上限为 " << path << "% 时：" << endl;
        if (total_schemes == 0) {
            cout << "  未找到满足条件的方案。" << endl;
        }
        else {
            cout << "  满足条件的方案总数为: " << total_schemes << endl;
        }
        cout << "------------------------------------" << endl;
    }

    return 0;
}