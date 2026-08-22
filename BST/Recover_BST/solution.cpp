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
    void fun(TreeNode* root, TreeNode*& prev,int &g, TreeNode*& g1first, TreeNode*& g1second,
             TreeNode*& g2first, TreeNode*& g2second) {
        if (root == NULL) {
            return;
        }
        fun(root->left, prev,g, g1first, g1second, g2first, g2second);
        if (prev == NULL) {
            prev = root;
        } else {
            if (root->val <= prev->val) {
                if (g == 0) {
                    g1first = prev;
                    g1second = root;
                } else {
                    g2first = prev;
                    g2second = root;
                }
                g++;
            }
            prev = root;
        }

        fun(root->right, prev,g, g1first, g1second, g2first, g2second);
        return;
    }
    void recoverTree(TreeNode* root) {
        int g = 0;
        TreeNode* g1first; 
        TreeNode*  g1second;
        TreeNode*  g2first; 
        TreeNode* g2second;
        TreeNode* prev = NULL;
        fun(root, prev, g, g1first, g1second, g2first, g2second);
        if (g == 1) {
            swap(g1first->val, g1second->val);
        } else {
            swap(g1first->val, g2second->val);
        }
    }
};
