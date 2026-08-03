#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using LD = long double;
//比较精度
LD e = 1e-6;
struct node
{
    int idx;
    int n;
    int w;
};
struct gnode
{
    int d;
    int i;
    int j;

};
struct ansnode
{
    vector<int>arr;
    LD G;
    LD seatrate;
    long long p;
    LD p1;
};
vector<vector<gnode>> d(11, vector<gnode>(10));
bool cmp(gnode a, gnode b)
{
    return a.d < b.d;
}
vector<node> arr(46);
long long suffix_n[47]; 
int solution_count = 0; 
int dmax = INT_MIN, dmin = INT_MAX;
long long pmax = 91187, pmin = 70637;
LD F = 0.0;
vector<ansnode>ans;
bool check(vector<int>& seats, int total)
{
    int tem = 5670;
    int sum = 0;
    for (int i = 0; i < seats.size(); i++) sum += seats[i];
    if (sum < 5670) return false;
    // 10 * 5668 >= 8 * sum  => sum <= 7085
    // 100 * 5668 <= 100 * sum => sum >= 5668
    if (10 * tem >= 8 * sum && 100 * tem <= 100 * sum) return true;
    return false;
}

LD seatrate(vector<int>& seats)
{
    int tem = 5670;
    int sum = 0;
    for (int i = 0; i < seats.size(); i++) sum += seats[i];
    return(LD)tem / sum;
}
LD p1(long long p)
{
    return (LD)(pmax - p) / (LD)(pmax - pmin);
}
LD f(LD g, LD p)
{
    return g * g + p * p;
}
LD G(int d, int num)
{
    return (LD)(dmax - d) / (LD)(dmax - dmin) * num / 5670.0;
}
LD Gmax(vector<int>& rooms)
{
    
    vector<int>res(10, 0);
    LD g = 0.0;
    for (int i = 0; i < rooms.size(); i++)
    {  
        //0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        //0 0 0 0 0 1 1 1 1 1 2  2  2  2  2  3
        int idx = rooms[i];
        if (idx % 5 == 0)res[idx / 5] += arr[idx].n;
        else res[idx/5+1] += arr[idx].n;
    }
    for (int i = 1; i <= 10; i++)
    {
        int people =567;
        for (int j = 1; j <= 9; j++)
        {
            int j1 = d[i][j].j;
            if (res[j1] <= 0)continue;
            int now = res[j1];
            int pu = min(now, people);
            res[j1] -= pu;
            people -= pu;
            g += G(d[i][j].d, pu);
            if (people == 0)break;
        }
    }
    return g;
}

void dfs(int idx, int current_sum, long long current_w, vector<int>& rooms, vector<int>& seats)
{
    if (current_sum > 7087) return;

    if (current_sum + suffix_n[idx] < 5670) return;

    LD cp1 = p1(current_w);
    if (F > 0 && (1.0 + (cp1 > 0 ? cp1 * cp1 : 0)) < F - e) return;

    if (idx > 45)
    {
        LD gtem = Gmax(rooms);
        LD ftem = f(gtem, cp1);

        if (ftem > F + e)
        {
            F = ftem;
            ans.clear();
            ans.push_back({ rooms, gtem, (LD)5670 / current_sum, current_w, cp1 });
        }
        else if (fabsl(F - ftem) <= e)
        {
            ans.push_back({ rooms, gtem, (LD)5670 / current_sum, current_w, cp1 });
        }
        return; 
    }

    rooms.push_back(arr[idx].idx);
    seats.push_back(arr[idx].n);
    dfs(idx + 1, current_sum + arr[idx].n, current_w + arr[idx].w, rooms, seats);
    rooms.pop_back();
    seats.pop_back();
    dfs(idx + 1, current_sum, current_w, rooms, seats);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("问题2input.txt", "r", stdin);
    freopen("问题2output.txt", "w", stdout);

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            int x;
            cin >> x;
            d[i][j] = { x,i,j };
            dmax = max(dmax, x);
            dmin = min(dmin, x);
        }
    }
    for (int i = 1; i <= 10; i++)sort(d[i].begin(), d[i].end(), cmp);
    for (int i = 1; i <= 45; i++) 
    {
        int val; cin >> val;
        arr[i].idx = i;
        arr[i].n = val;
    }
    for (int i = 1; i <= 45; i++) 
    {
        int val; cin >> val;
        arr[i].w = val;
    }

    memset(suffix_n, 0, sizeof(suffix_n));
    for (int i = 45; i >= 1; i--) {
        suffix_n[i] = suffix_n[i + 1] + arr[i].n;
    }

    vector<int> current_rooms;
    vector<int> current_seats;
   // cout << "正在搜索所有满足条件的方案...\n\n";
    dfs(1, 0, 0, current_rooms, current_seats);
    //cout << "\n搜索完成，共找到 " << solution_count << " 种方案。" << endl;
    cout << "共有:" << ans.size() << "种方案，其中接受度为：" << sqrtl(F);
    cout << '\n';
    for (long long i = 1; i <= ans.size(); i++)
    {
        cout << "方案" << i << "为：:\n";
        vector<int>rooms = ans[i - 1].arr;
        for (int i = 0; i < rooms.size(); i++) cout << rooms[i] << (i == rooms.size() - 1 ? "" : " ");
        cout << '\n';
        cout << "其中满座率为：" << ans[i - 1].seatrate << " 最大满意度为：" << ans[i - 1].G << " 耗电量为：" << ans[i - 1].p << " 归一化的耗电量为：" << ans[i - 1].p1;
        cout << '\n';
    }

    return 0;
}