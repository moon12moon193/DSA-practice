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
void fun(TreeNode* root,int &sum, int &total){
    if(root==NULL){
        return;
    }
    sum=sum*10+root->val;
    if(root->left==NULL && root->right==NULL){
        total=total+sum;
    }
    fun(root->left,sum,total);
    fun(root->right,sum,total);
    sum=sum/10;
    return;
}
    int sumNumbers(TreeNode* root) {
        int total=0;
        int sum=0;
        fun(root,sum,total);
        return total;
        
    }
};
