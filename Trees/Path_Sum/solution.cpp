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
    void fun(TreeNode* root, int targetSum, int &sum, bool &res) {
        if (root == NULL) {
            return;
        }
        sum = sum + root->val;
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                res = true;
                
            }
        }

        fun(root->left, targetSum, sum, res);
        fun(root->right, targetSum, sum, res);
        sum = sum - root->val;
        return;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool res = false;
        fun(root, targetSum, sum, res);
        return res;
    }
};
