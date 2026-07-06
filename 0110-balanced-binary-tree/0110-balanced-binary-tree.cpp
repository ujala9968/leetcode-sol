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
    int hieght(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = hieght(root->left);
        int right = hieght(root->right);
        return max(left,right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int lh = hieght(root->left);
        int rh = hieght(root->right);
        if(abs(lh-rh) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};