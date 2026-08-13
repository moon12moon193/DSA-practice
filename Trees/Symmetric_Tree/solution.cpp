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
bool fun(TreeNode* root1,TreeNode* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL || root2==NULL){
        return false;
    }
    if(root1->val!=root2->val){
        return false;
    }
    bool v1=fun(root1->left,root2->right);
    bool v2=fun(root1->right,root2->left);
    if(v1==true && v2==true){
        return true;
    }else{
        return false;
    }
}
    bool isSymmetric(TreeNode* root) {
     bool ans=fun(root->left,root->right);
     return ans;
        
    }
};
