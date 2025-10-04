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
public:
    TreeNode* solve(TreeNode* root, int val){
        //base case
        if(root == NULL){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        //left
        if(root->val > val){
          root->left = solve(root->left,val);
        }
        //right
         if(root->val < val){
             root->right = solve(root->right,val);
        }

        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return solve(root,val);

        
    }
};