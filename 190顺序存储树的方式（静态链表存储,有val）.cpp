#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int>L(N, 0), R(N, 0), VAL(N, 0), P(N, 0);
int n;
int getroot()
{
    for (int i = 1; i <= n; i++)if (P[i] == 0)return i;
    return 1;
}
void preorder(int root)
{
    if (root == 0)return;
    cout << VAL[root] << ' ';
    preorder(L[root]);
    preorder(R[root]);
}
void inorder(int root)
{
    if (root == 0)return;
    inorder(L[root]);
    cout << VAL[root] << ' ';
    inorder(R[root]);
}
void postorder(int root)
{
    if (root == 0)return;
    postorder(L[root]);
    postorder(R[root]);
    cout << VAL[root] << ' ';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int idx, val, l, r;
        cin >> idx >> val >> l >> r;
        VAL[idx] = val;
        L[idx] = l;
        R[idx] = r;
        if (l != 0)P[l] = idx;
        if (r != 0)P[r] = idx;
    }
    int root = getroot();
    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    return 0;
}
