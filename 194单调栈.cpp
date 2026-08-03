#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
void out(vector<int>& arr)
{
    for (auto num : arr)cout << num << ' ';
    cout << '\n';
}
//寻找当前元素左侧，离它最近，并且⽐它⼤的元素在哪
vector<int> ms1(vector<int>& arr)
{
    vector<int>ret;
    stack<int>stk;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!stk.empty() && arr[stk.top()] <= arr[i])stk.pop();
        if (!stk.empty())ret.push_back(stk.top());
        else ret.push_back(-1);
        stk.push(i);
    }
    return ret;
}
//寻找当前元素左侧，离它最近，并且⽐它⼩的元素在哪；
vector<int> ms2(vector<int>& arr)
{
    vector<int>ret;
    stack<int>stk;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])stk.pop();
        if (!stk.empty())ret.push_back(stk.top());
        else ret.push_back(-1);
        stk.push(i);
    }
    return ret;
}
//寻找当前元素右侧，离它最近，并且⽐它⼤的元素在哪
vector<int> ms3(vector<int>& arr)
{
    vector<int>ret(arr.size(),-1);
    stack<int>stk;
    for (int i=arr.size()-1;i>=0;i--)
    {
        while (!stk.empty() && arr[stk.top()] <= arr[i])stk.pop();
        if (!stk.empty())ret[i] = stk.top();
        stk.push(i);
    }
    return ret;
}
//寻找当前元素右侧，离它最近，并且⽐它⼩的元素在哪
vector<int> ms4(vector<int>& arr)
{
    vector<int>ret(arr.size(), -1);
    stack<int>stk;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] >= arr[i])stk.pop();
        if (!stk.empty())ret[i] = stk.top();
        stk.push(i);
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>arr(n);
    for (auto& num : arr)cin >> num;
    vector<int>ret;
    ret = ms4(arr);
    out(ret);
    return 0;
}
