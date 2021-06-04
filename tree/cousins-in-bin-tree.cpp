// https://leetcode.com/problems/cousins-in-binary-tree/

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
    void Inorder(TreeNode *root,map<int,pair<int,int>> &mp,int level,int parent)
    {
        if(!root)   return;
        Inorder(root->left,mp,level+1,root->val);
        int curr = root->val;
        mp[curr] =
            make_pair(level,parent);
        Inorder(root->right,mp,level+1,root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        map<int,pair<int,int>> mp;
        Inorder(root,mp,1,-1);
        if(mp[x].first == mp[y].first && mp[x].second != mp[y].second)
            return true;
        else
            return false;
        
    }
};