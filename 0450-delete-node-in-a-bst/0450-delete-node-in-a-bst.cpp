/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, int key) {
        // base case
        if (root == NULL) {
            return NULL;
        }

        // when equal thingd happen
        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } else if (root->left != NULL && root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if (root->left == NULL && root->right != NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else {
                TreeNode* temp = root->right;
                TreeNode* par = root;

                while (temp->left != NULL) {
                    par = temp;
                    temp = temp->left;
                }
                root->val = temp->val;

                // unlink the successor node
                if (par == root) {
                    // successor was direct right child
                    par->right = temp->right;
                } else {
                    // successor was in left subtree
                    par->left = temp->right;
                }

                delete temp;
            }
        }

        // move to left
        if (root->val > key) {
            root->left = solve(root->left, key);
        }

        // move to right
        if (root->val < key) {
            root->right = solve(root->right, key);
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) { return solve(root, key); }
};