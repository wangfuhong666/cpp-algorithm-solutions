/*#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
vector<PII>arr(45);
vector<bool>vis(45, false);

long long res = 0;
long long count1 = 0;
bool cmp(PII a, PII b)
{
	return a.first > b.first;
}
void dfs(int pos, int sum) {
    if (pos == 45) 
    {
        count1++;
        cout << "方案" << count1 << "为：";
        vector<int>cnt;
        for (int i = 0; i < 45; i++) 
        {
            if (!vis[i]) 
            {
                cnt.push_back(arr[i].second); 
            }
        }
        sort(cnt.begin(), cnt.end());
        for (auto e : cnt)cout << e << ' ';
        cout << "\n";
        return;
    }
    //if (count1 > 500)return;
    vis[pos] = false;
    dfs(pos + 1,sum);
    if (sum + arr[pos].first <=res)
    {
        vis[pos] = true;
        dfs(pos + 1, sum + arr[pos].first);
        vis[pos] = false;
    }
    return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("111.txt", "r", stdin);
	freopen("anstem.txt", "w", stdout);
    int sum = 0;
	for (int i = 1; i <= 45; i++)
	{
		int x;
		cin >> x;
        sum += x;
		arr[i - 1] = { x,i };
	}
	sort(arr.begin(), arr.end(), cmp);
    res = sum - 5668;
    dfs(0, 0);
	return 0;
}*/
/**#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;
struct node
{
    int idx;
    int n;
    int w;
    double t;
};
//1.最小满座率>=90%||最大满座率<=80%（不要）
long long x = LLONG_MAX;//统计一下最小耗电量
vector<node>arr(45);
vector<int>path;
vector<int>res;
bool judge = false;
bool cmp(node a, node b)
{
    return a.t < b.t;
}
void dfs(int pos, int sum, int dx)
{
    if (judge)return;
    if(pos==45)
    {
        if (sum < 5668)return;
        vector<int>ans;
        for (auto e : path)
        {
            ans.push_back(arr[e].n);
        }
        int tem = 5668;
        int i;
        sort(ans.begin(), ans.end());
        for (i = 0; i < ans.size(); i++)
        {
            if (tem < 0)break;
            tem -= ans[i];
        }
        if (i * 100 > 95 * ans.size())return;
        tem = 5668;
        sort(ans.begin(), ans.end(),greater<int>());
        for (i = 0; i < ans.size(); i++)
        {
            if (tem < 0)break;
            tem -= ans[i];
        }
        if (i * 10 < 8 * ans.size())return;
        if (dx < x)
        {
            x = dx;
            res = path;
            judge = true;
        }
        return;
    }
    if (dx > x)return;
    if (judge)return;
    //dfs(pos + 1, sum, dx);
    path.push_back(pos);
    dfs(pos + 1, sum + arr[pos].n, dx+arr[pos].w);
    path.pop_back();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("111.txt", "r", stdin);
    freopen("最优方案.txt", "w", stdout);
    for (int i = 1; i <= 45; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i-1].idx = i;
        arr[i-1].n = tmp;
    }
    for (int i = 1; i <= 45; i++)
    {
        int tmp;
        cin >> tmp;
        arr[i-1].w = tmp;
        arr[i - 1].t = (double)(tmp) / arr[i-1] . n;
    }
    sort(arr.begin(), arr.end(), cmp);
    dfs(0, 0, 0);
    cout << "最优方案为：";
    for (auto e : res)cout << e << ' ';
    cout << "这个方案的总耗电量为：";
}*/
/*int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("111.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    vector<int>arr(46, 0);
    int sum = 0;
    for (int i = 1; i <= 45; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    vector < vector<long long>>dp(46, vector<long long>(sum + 1, 0));
    dp[0][0] = 1;
    long long res = 0;
    for (int i = 1; i <= 45; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arr[i])dp[i][j] += dp[i - 1][j - arr[i]];
            if (dp[i][j] >= 5668)res += dp[i][j];
        }
    }
    cout << res;
    return 0;
}*/

