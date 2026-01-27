#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<ctime>
#define MAX 93
using namespace std;
//DP+递归6
long long arr[MAX];
int call_cnt[MAX] = { 0 }; // 调用次数计数数组

long long fun(int n)
{
    call_cnt[n]++;  // 每次调用计数+1
    if (arr[n] != 0)
    {
        return arr[n];
    }
    else
    {
        if (n == 1 || n == 2) { arr[n] = 1; return arr[n]; }
        else { arr[n] = fun(n - 1) + fun(n - 2); return arr[n]; }
    }
}

int main()
{
    auto A = clock();
    memset(arr, 0, sizeof arr);
    fun(92);

    // 输出斐波那契数列（原格式不变）
    for (int i = 1; i <= 92; ++i) {
        cout << "F_" << setw(2) << i << " = " << setw(20) << arr[i];
        if (i % 5 == 0) {
            cout << endl;
        }
        else {
            cout << "  ";
        }
    }

    auto B = clock();
    cout << endl << "总用时： " << llabs((long long)(B - A)) << " 时钟周期" << endl;

    // ========== 优化后的调用次数输出 ==========
    cout << "\nfun(1)~fun(92) 调用次数统计：" << endl;
    cout << "----------------------------------------" << endl;
    for (int i = 1; i <= 92; ++i) {
        // 固定宽度：项数占3位，次数占4位，用 | 分隔更清晰
        cout << "f(" << setw(2) << i << ")=" << setw(3) << call_cnt[i] << " ";
        // 每 12 项换一行，避免单行过长
        if (i % 12 == 0) {
            cout << endl;
        }
    }
    cout << endl;

    return 0;
}
