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
    void fun(TreeNode* root,int targetSum,int sum,vector<int>& temp,vector<vector<int>>& res){
        if(root==NULL){
            return;
        }
        sum=sum+root->val;
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                res.push_back({temp});
            }
        }
        fun(root->left,targetSum,sum,temp,res);
        fun(root->right,targetSum,sum,temp,res);
        sum=sum-root->val;
        temp.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>temp;
        int sum=0;
        fun(root,targetSum,sum,temp,res);
        return res;
        
    }
};
