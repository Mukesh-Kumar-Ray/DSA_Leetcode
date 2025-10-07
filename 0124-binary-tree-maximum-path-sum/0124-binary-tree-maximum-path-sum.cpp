/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    int solve(TreeNode* node , int &maxi){
        if(node ==NULL){
            return 0;
        }
        int lft=max(0,solve(node->left,maxi));
        int rft=max(0,solve(node->right,maxi));

        maxi=max((lft+rft+node->val),maxi);

        return (max(lft,rft)+node->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
         solve(root,maxi);
         return maxi;

        
    }
};