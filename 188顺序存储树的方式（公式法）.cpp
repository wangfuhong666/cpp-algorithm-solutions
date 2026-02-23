#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int>tree(N, -1);
//给出元素个数（完全二叉树）（如给出深度直接1<<n）
int n;
void preorder(int root)
{
    if (root > n) return;
    if (tree[root] == -1)return;
    cout << tree[root] << ' ';
    preorder(2 * root);
    preorder(2 * root + 1);

}
void inorder(int root)
{
    if (root > n) return;
    if (tree[root] == -1)return;   
    inorder(2 * root);
    cout << tree[root] << ' ';
    inorder(2 * root + 1);

}
void postorder(int root)
{
    if (root > n) return;
    if (tree[root] == -1)return;   
    postorder(2 * root);  
    postorder(2 * root + 1);
    cout << tree[root] << ' ';

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);       
    cin >> n;   
    for (int i = 1; i <= n; i++)cin >> tree[i];
    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
    return 0;
}
