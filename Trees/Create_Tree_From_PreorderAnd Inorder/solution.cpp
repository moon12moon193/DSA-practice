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
    TreeNode* fun(vector<int>& preorder, unordered_map<int, int>& f, int &index,
                  int low, int high) {
        if (low > high) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        int id = f[root->val];
        root->left = fun(preorder, f, index, low, id - 1);
        root->right = fun(preorder, f, index, id + 1, high);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> f;
        for (int i = 0; i < inorder.size(); i++) {
            f[inorder[i]] = i;
        }
        int index = 0;
        int low = 0;
        int high = preorder.size() - 1;
        TreeNode* root = fun(preorder, f, index, low, high);
        return root;
    }
};
