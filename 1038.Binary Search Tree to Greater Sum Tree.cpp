//把二叉搜索树的结点值
class Solution {
    int pre = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(root){
            bstToGst(root->right);
            pre += root->val;
            root->val = pre;
            bstToGst(root->left);
        }
        return root;
    }
};