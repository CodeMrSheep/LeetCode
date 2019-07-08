/*先序遍历二叉树，对于每一个节点都有记录了一条从根节点到当前节点到路径，
同时用一个变量 curSum 记录路径节点总和，然后我们看 curSum 和 sum 是否相等，
相等的话结果 res 加1，不等的话我们来继续查看子路径和有没有满足题意的，做法就是每次去掉一个节点，
看路径和是否等于给定值，注意最后必须留一个节点，不能全去掉了，因为如果全去掉了，
路径之和为0，而如果给定值刚好为0的话就会有问题*/
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*> subpath;
        helper(root,sum,0,subpath,res);
        return res;
    }
    void helper(TreeNode* root,int sum,int cursum,vector<TreeNode*>& sub,int& res){
        if(!root) return;
        cursum += root->val;
        sub.push_back(root);
        if(cursum == sum) res++;
        int tmp = cursum;
        for(int i = 0;i<sub.size()-1;i++){
            tmp -= sub[i]->val;
            if(tmp == sum) res++;
        }
        helper(root->left,sum,cursum,sub,res);
        helper(root->right,sum,cursum,sub,res);
        sub.pop_back();
    }
};