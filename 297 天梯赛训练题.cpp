#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int y;
    int mo;
    int d;
    int h;
    int m;
    int s;
    int id;
    int score;
    node() :y(INT_MAX){}
    node(int y, int mo, int d, int h, int m, int s, int id, int score) :y(y), mo(mo), d(d), h(h), m(m), s(s), id(id), score(score) {}
};
bool cmp(node a, node b)
{
    if (a.y != b.y)return a.y < b.y;
    if (a.mo != b.mo)return a.mo < b.mo;
    if (a.d != b.d)return a.d < b.d;
    if (a.h != b.h)return a.h < b.h;
    if (a.m != b.m)return a.m < b.m;
    return a.s < b.s;
}
string out(node a)
{
    int y = a.y;
    int mo = a.mo;
    int d = a.d;
    int h = a.h;
    int m = a.m;
    int s = a.s;
    int id = a.id;
    int score = a.score;
    //2023-06-01 10:23:10 3 12
    string res = "";
    res += string(4 - to_string(y).size(), '0') + to_string(y) + "-" + string(2 - to_string(mo).size(), '0') + to_string(mo) + "-";
    res+= string(2 - to_string(d).size(), '0') + to_string(d) + " ";
    res+= string(2 - to_string(h).size(), '0') + to_string(h) + ":";
    res+= string(2 - to_string(m).size(), '0') + to_string(m) + ":";
    res += string(2 - to_string(s).size(), '0') + to_string(s) + " ";
    res += to_string(id) + " " + to_string(score);
    return res;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<node>arr(n);
    for (int i = 0; i < n; i++)
    {
        int y;
        int mo;
        int d;
        int h;
        int m;
        int s;
        int id;
        int score;
        scanf("%d-%d-%d %d:%d:%d %d %d", &y, &mo, &d, &h, &m, &s, &id, &score);
        arr[i] = { y,mo,d,h,m,s,id,score };
    }
    sort(arr.begin(), arr.end(), cmp);
    vector<node>info(m + 1);
    vector<int>maxn(m + 1, -1);
    for (int i = 0; i < n; i++)
    {
        node tem = arr[i];
        int id = tem.id;
        int score = tem.score;
        if (score > maxn[id])
        {
            info[id] = tem;
            maxn[id] = score;
        }
    }
    int p = 0;
    for (int i = 1; i <= m; i++)
    {
        if (maxn[i] == -1)continue;
        p++;
    }
    sort(info.begin(), info.end(), cmp);
    for (int i = 0; i < p; i++)cout << out(info[i]) << '\n';
    return 0;
}
