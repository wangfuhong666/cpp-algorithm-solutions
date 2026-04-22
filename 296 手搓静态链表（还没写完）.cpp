#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int>val(maxn, 0);
vector<int>ne(maxn, 0);
int pos = 0;
int head = 0;
void headinsert(int x)
{
    pos++;
    val[pos] = x;
    ne[pos] = ne[head];
    ne[head] = pos;

}
int gettail()
{
    int i = head;
    while (ne[i] != 0)i = ne[i];
    return i;
}
void tailinsert(int x)
{
    int idx = gettail();
    pos++;
    val[pos] = x;
    ne[idx] = pos;
    ne[pos] = 0;
}
void out()
{
    for (int i = ne[head]; i ; i = ne[i])cout << val[i] << ' ';
    cout << '\n';
}
//返回链表中元素个数，头节点除外
int getnums()
{
    int count = 0;
    int i = ne[head];
    while (i)
    {
        count++;
        i = ne[i];
    }
    return count;
}
void insert(int ps, int x)
{
    int pos1 = 0;
    for (int i = i = 1; i <= ps - 1; i++)
    {
        if (!pos1)return;
        pos1 = ne[pos1];
    }
    if (!ne[pos1])tailinsert(x);
    pos++;
    val[pos] = x;
    ne[pos] = ne[pos1];
    ne[pos1] = pos;
}
void erase(int ps)
{
    int pos1 = 0;
    for (int i = i = 1; i <= ps - 1; i++)
    {
        if (!pos1|| !ne[pos1])return;
        pos1 = ne[pos1];
    }
    ne[pos1] = ne[ne[pos1]];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 1; i <= 50; i++)
    {
        if (i % 2)headinsert(i);
        else tailinsert(i);
    }
    out();
    erase(5);
    out();
    
    return 0;
}
