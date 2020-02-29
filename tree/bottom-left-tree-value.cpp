// https://leetcode.com/problems/find-bottom-left-tree-value/submissions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,int level,vector<int> &l_view)
    {
        if(root==NULL)  return;
        if(level > l_view.size())
        {
            l_view.push_back(root->val);
        }
        dfs(root->left,level+1,l_view);
        dfs(root->right,level+1,l_view);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> l_view;
        dfs(root,1,l_view);
        return l_view[l_view.size()-1];
    }
};