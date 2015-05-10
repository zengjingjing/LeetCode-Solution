/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool IsLeaf(TreeNode * node)
 {
     if(node->left == NULL && node->right == NULL)return true;
     return false;
 }
void  Traversal(TreeNode* root, vector<int>& ans)
{
    if(!root)return;
    Traversal(root->left, ans);
    ans.push_back(root->val);
     Traversal(root->right, ans);
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
       vector<int> ans;
       Traversal(root, ans);
       return ans;
    }
};