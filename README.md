# cpp-algorithm-solutions

我的算法竞赛刷题记录，全部用 C++ 实现，按刷题顺序编号，一个文件一道题。

刷题主力平台是洛谷和牛客，同时覆盖力扣、蓝桥云课、Codeforces、AtCoder 以及 ICPC / CCPC 等赛事的现场题。

## 进度

| 平台 | 题量 |
| --- | --- |
| 洛谷 | 140 |
| 牛客 | 101 |
| 力扣 | 23 |
| 蓝桥云课 | 15 |
| Codeforces | 13 |
| AtCoder / ICPC / CCPC / UVA | 16 |
| **合计** | **805** |

## 目录

所有代码位于 [`solutions/`](solutions/)，文件名为 `编号 + 算法标签 + （题目来源与题号）`，编号即刷题顺序。

## 常用模板

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void sol() {}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) sol();
    return 0;
}
```

## 已完成知识点

- **基础**：模拟、枚举、位运算、前缀和、差分、双指针、二分答案
- **贪心**：区间问题、推公式、交换论证
- **搜索**：DFS / BFS、回溯、连通块、记忆化搜索
- **动态规划**：线性 DP、背包、区间 DP、树形 DP、状压 DP、轮廓线 DP
- **数据结构**：并查集、堆、单调栈 / 队列、树状数组、ST 表、线段树
- **图论**：最短路（Dijkstra / Floyd / Bellman-Ford）、最小生成树、LCA、Tarjan、拓扑排序
- **数学**：质因数分解、线性筛、区间筛、GCD / EXGCD、欧拉函数、快速幂、高精度
- **字符串**：KMP、字符串匹配

## 备注

- 部分编号（478 及之后）为代码模板预留位，尚未填入具体题目。
- 提交说明统一为「同步代码」。
