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
bool fun(TreeNode* root,bool &isNullFound){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* t=q.front();
        q.pop();
        if(t==NULL){
            isNullFound=true;
        }else{
            if(isNullFound==true){
                return false;
            }
            q.push(t->left);
            q.push(t->right);
        }
    }
    return isNullFound;
}
    bool isCompleteTree(TreeNode* root) {
        bool isNullFound=false;
      bool ans=fun(root,isNullFound);
      return ans;
        
    }
};
