// https://leetcode.com/problems/binary-tree-cameras/

// You are given the root of a binary tree. We install cameras on
// the tree nodes where each camera at a node can monitor its parent,
// itself, and its immediate children.

// Return the minimum number of cameras needed to monitor all
// nodes of the tree.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int res = 0;
    int minCameraCover(TreeNode *root)
    {
        return (dfs(root) < 1 ? 1 : 0) + res;
    }

    int dfs(TreeNode *root)
    {
        if (!root)
            return 2;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == 0 || right == 0)
        {
            res++;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}