#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<utility>
using namespace std;
struct Node {
	long long x, y;
	int idx;
	//数组下标（从一开始的）
};
//图
// map
//二分 
//数组中的元素 有序
//1 3 2 8 5 6
//0 1 2 3 4 5 

//qsort
bool cmp(const Node& a, const Node& b) {
	if (a.x != b.x) return a.x < b.x;
	if (a.y != b.y) return a.y < b.y;
	return a.idx < b.idx;
}
// x y idx
// 0 0 0 0
// 1 1 2 3
// 2 3 1 0
// 
//二分+线性扫描（不超时，代码量较少）
//x 0 0 0 1 1 1 1 2 2 2 2 3 3 3 5 5 5 5 6 6 6 6 6
//x  =  3
bool query_1(long long target_x, long long target_y, int L, int R, vector<Node>& nodes) {

	int left = 0, right = nodes.size();
	while (left < right) {
		//下取整
		//查找 第一个x==target_x的位置
		int mid = (left + right) / 2;
		if (nodes[mid].x < target_x) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}


	for (int i = left; i < nodes.size() && nodes[i].x == target_x; i++) {
		if (nodes[i].y == target_y && nodes[i].idx >= L && nodes[i].idx <= R) {
			return true;  
		}
	
		if (nodes[i].y > target_y) break;
	}
	return false;
}
//纯二分（绝对不超时，代码执行效率最高，代码量较大）
bool query(long long target_x, long long target_y, int L, int R, vector<Node>& nodes) {
	int left = 0, right = nodes.size();
	while (left < right) {
		int mid = (left + right) / 2;
		if (nodes[mid].x < target_x) left = mid + 1;
		else right = mid;
		
	}
	int start = left;
	right = nodes.size();
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (nodes[mid].x <= target_x)left = mid + 1;
		else right = mid;
	}
	int end = left - 1;
	if (start > end) {
		return false;
	}
	left = start;
	right = end;
	while (left <= right) 
	{
		int mid = (left + right) / 2;
		if (nodes[mid].y == target_y) 
		{
			if (nodes[mid].idx >= L && nodes[mid].idx <= R) return true;
			if (nodes[mid].idx < L) left = mid + 1;
			else right = mid - 1;
		}
		else if (nodes[mid].y < target_y) left = mid + 1;
		else right = mid - 1;
	}

	return false;
}

//1 1 1 1 1 1
//0 1 1 2 5 5 
//0 1 2 3 4 5
// 0 0 0 0 0 0 0 0 0 0 0 0 00 0 0 0 0 0 00 0 0
 5 5 5 5 55 5  55 5 5 5
 o(n)
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	//前缀和运算
	vector<long long>prex(n + 1, 0);
	vector<long long>prey(n + 1, 0);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L')prex[i + 1] -= 1;
		if (s[i] == 'R')prex[i + 1] += 1;
		if (s[i] == 'U')prey[i + 1] += 1;
		if (s[i] == 'D')prey[i + 1] -= 1;
	}
	for (int i = 1; i <= n; i++)
	{
		prex[i] += prex[i - 1];
		prey[i] += prey[i - 1];
	}
	vector<Node> nodes(n + 1);
	for (int i = 0; i <= n; i++) {
		nodes[i] = { prex[i], prey[i], i };
	}
	sort(nodes.begin(), nodes.end(), cmp);
//1.前缀和O(N)
// 2.结构体数组O(N)
// 3.结构体数组排序（x,y,idx）O(N*logN)
//
//NlogN
 qlogn
 qn
	while (q--)
	{
		bool judge = false;
		long long posx = 0;
		long long posy = 0;
		long long l, r, x, y;
		cin >> l >> r >> x >> y;
		if (x == 0 && y == 0)
		{
			cout << "YES" << endl;
			continue;
		}
		judge = query(x, y, 0, l - 1, nodes);
		//1 l-1 
		if (!judge && r < n)
		{
			//l-r
			long long tx = x + (prex[r] - prex[l - 1]);
			long long ty = y + (prey[r] - prey[l - 1]);
			judge = query(tx, ty, r + 1, n, nodes);
		}
		if (judge)cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}
