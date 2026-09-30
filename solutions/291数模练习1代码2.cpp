#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

struct node {
    int idx;
    int n;
    int w;
    double t;
};
int iii;
struct dpnode
{
    long long min_w;
    int cnt;
    vector<int> rooms;
    vector<int> seats;
    dpnode() : min_w(LLONG_MAX/2), cnt(0) {}
    dpnode(long long w, int c, vector<int> r, vector<int> s) : min_w(w), cnt(c), rooms(r), seats(s) {}
};
long long x = LLONG_MAX/2;
vector<node> arr(45);
vector<int> res;
bool cmp(const node& a, const node& b)
{
    return a.t < b.t;
}

bool check(vector<int>& seats, int total) 
{
    int tem = 5668;
    int i;
    vector<int> ans = seats;
    sort(ans.begin(), ans.end(),less<int>());
    for (i = 0; i < ans.size(); i++)
    {
        if (tem <= 0) break;
        tem -= ans[i];
    }
    if (i * 100 > iii * total) return false;

    tem = 5668;
    sort(ans.begin(), ans.end(), greater<int>());
    for (i = 0; i < ans.size(); i++)
    {
        if (tem <= 0) break;
        tem -= ans[i];
    }
    if (i * 10 < 8 * total) return false;

    return true;
}
void out(vector<int>& seats, int total) 
{
    int tem = 5668;
    int i;
    vector<int> ans = seats;
    sort(ans.begin(), ans.end());
    for (i = 0; i < ans.size(); i++)
    {
        if (tem <= 0) break;
        tem -= ans[i];
    }
    cout << "最大满座率为：" << (double)i / total << "\n";

    tem = 5668;
    sort(ans.begin(), ans.end(), greater<int>());
    for (i = 0; i < ans.size(); i++)
    {
        if (tem <= 0) break;
        tem -= ans[i];
    }
    cout << "最小满座率为：" << (double)i / total << "\n";


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("111.txt", "r", stdin);
    freopen("问题1output.txt", "w", stdout);
    for (int i = 1; i <= 45; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i - 1].idx = i;
        arr[i - 1].n = tmp;
    }
    for (int i = 1; i <= 45; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i - 1].w = tmp;
        arr[i - 1].t = (double)tmp / arr[i - 1].n;
    }
    sort(arr.begin(), arr.end(), cmp);
    for (iii = 90; iii <= 100; iii++)
    {
        x = LLONG_MAX / 2;
        res.clear();
        int sumseat = 0;
        for (auto& room : arr) sumseat += room.n;

        vector<dpnode> dp(sumseat + 1);
        dp[0] = dpnode(0, 0, {}, {});


        for (int i = 0; i < 45; ++i)
        {
            int n_i = arr[i].n;
            int w_i = arr[i].w;
            for (int s = sumseat; s >= n_i; s--)
            {
                if (dp[s - n_i].min_w == LLONG_MAX / 2) continue;
                long long new_w = dp[s - n_i].min_w + w_i;
                int new_cnt = dp[s - n_i].cnt + 1;
                vector<int> new_rooms = dp[s - n_i].rooms;
                vector<int> new_seats = dp[s - n_i].seats;
                new_rooms.push_back(i);
                new_seats.push_back(n_i);

                if (new_w < dp[s].min_w || (new_w == dp[s].min_w && new_cnt < dp[s].cnt))
                {
                    dp[s] = dpnode(new_w, new_cnt, new_rooms, new_seats);
                }
            }
        }
        int s1 = -1;
        for (int s = 5668; s <= sumseat; s++) 
        {
            if (dp[s].min_w == LLONG_MAX / 2) continue;
            if (check(dp[s].seats, dp[s].cnt)) 
            {
                if (dp[s].min_w < x) 
                {
                    x = dp[s].min_w;
                    res = dp[s].rooms;
                    s1 = s;
                }
            }
        }

        if (s1 == -1)
        {
            cout << "最大满座率小于等于：" << iii << "时 ";
            cout << "未找到满足条件的方案！" << endl;
            continue;
        }
        cout << "最大满座率小于等于：" << iii << "时 ";
        cout << "最优方案为：";
        vector<int>tem;

        for (auto e : res)
        {
            tem.push_back(arr[e].idx);
        }
        sort(tem.begin(), tem.end());
        for (auto e : tem)
        {
            cout << e << ' ';
        }
        cout << "\n这个方案的总耗电量为：\n" << x << endl;
        out(dp[s1].seats, dp[s1].cnt);
    }

    return 0;
}
