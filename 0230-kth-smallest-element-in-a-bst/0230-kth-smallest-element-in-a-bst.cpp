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
    int ans;
    int c=0;
    void inorder(TreeNode * node , int s){
        if(node == NULL){
            return;
        }
        inorder(node->left , s);
        c++;
        if(c==s){
            ans = node->val;
            return;
        }
        inorder(node->right , s);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root , k);
        return ans;
    }
};