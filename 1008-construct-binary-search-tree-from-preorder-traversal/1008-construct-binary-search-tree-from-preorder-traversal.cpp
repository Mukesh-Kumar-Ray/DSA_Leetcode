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
    TreeNode* solve(TreeNode* root , TreeNode* node){
        //base case
        if(root == NULL){
            return node;
        }
        //left move
        if(root->val >node->val){
            root->left = solve(root->left , node);
        }
        //right move
        if(root->val <node->val){
            root->right = solve(root->right , node);
        }

        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i =1; i<preorder.size();i++){
            TreeNode* node = new TreeNode(preorder[i]);
            solve(root , node);
        }

        return root;
        
    }
};