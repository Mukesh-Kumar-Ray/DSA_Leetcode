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
    TreeNode* solve (TreeNode* root,int x,int y){
        //base case
        if(root == NULL){
            return NULL;
        }
         if((root->val > x && root->val < y) || (root->val < x && root->val > y)){
            return root;
        }
           //left move
         if(root->val > x && root->val > y){
            return solve(root->left,x,y);
        }

        //right move
        if(root->val < x && root->val < y){
            return solve(root->right,x,y);
        }

        return root;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p->val,q->val);        
    }
};