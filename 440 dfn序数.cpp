#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;


 struct TreeNode 
 {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 const int N=1e5+10;
class Solution 
{
vector<int>dfn,sz,h,maxl,maxr;
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfn.resize(N);
        sz.resize(N);
        h.resize(N);
        maxl.resize(N);
        maxr.resize(N);
        int id=1;
        dfs(root,id,0);
        for(int i=1;i<id;i++)maxl[i]=max(h[i],maxl[i-1]);
        for(int i=id-1;i>=1;i--)maxr[i]=max(h[i],maxr[i+1]);
        vector<int>res((int)queries.size());
        for(int i = 0;i<(int)queries.size();i++)
        {
            int q=queries[i];
            int s=dfn[q];
            res[i]=max(maxl[s-1],maxr[s+sz[s]]);
        }
        return res;
    }
private:
    int dfs(TreeNode* root,int& id,int d)
    {
        if(root==nullptr)return 0;
    
        int cur = id++;   
        dfn[root->val] = cur;
        h[cur] = d;
        return sz[cur] = dfs(root->left,id,d+1)+dfs(root->right,id,d+1)+1;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    //cin>>t;
    //while(t--)sol();
    return 0;
}
