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
    void fun(TreeNode* root, vector<vector<int>>& temp) {
        int levelOrder = 1;
        queue<TreeNode*> q;
        if (root == NULL) {
            return;
        }
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> ans(levelSize);
            int first = 0;
            int last = levelSize - 1;
            while (levelSize > 0) {
                TreeNode* t = q.front();
                q.pop();
                if (levelOrder == 1) {
                    ans[first] = t->val;
                    first++;
                } else {
                    ans[last] = t->val;
                    last--;
                }
                if (t->left != NULL) {
                    q.push(t->left);
                }
                if (t->right != NULL) {
                    q.push(t->right);
                }
                levelSize--;
            }
            temp.push_back(ans);
            levelOrder=1-levelOrder;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> temp;
        fun(root, temp);
        return temp;
    }
};
