// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
   
    void dfs(TreeNode* root,int p,int gp,int &sum)
    {
        if(root==NULL)  return;
        
        dfs(root->left,root->val,p,sum);
        
        if(gp%2==0) sum += root->val;
    
        dfs(root->right,root->val,p,sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        dfs(root,1,1,sum);
        return sum;
    }
};
