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
void fun(TreeNode* root,vector<vector<int>>&temp){
    if(root==NULL){
        return;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int levelSize=q.size();
        vector<int>ans;
        while(levelSize>0){
            TreeNode* t=q.front();
            q.pop();
            ans.push_back(t->val);
            if(t->left!=NULL){
                q.push(t->left);
            }
            if(t->right!=NULL){
                q.push(t->right);
            }
            levelSize--;
        }
        temp.push_back(ans);
    }
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>temp;
        fun(root,temp);
        return temp;
        
    }
};
