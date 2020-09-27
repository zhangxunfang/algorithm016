/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         TreeNode* pre = NULL;
//         return isValid(root, pre);
//     }
    
//     bool isValid(TreeNode* root, TreeNode* &pre){
//         if(!root) return true;
//         if(!isValid(root->left, pre)) return false;
//         if(pre && root->val <= pre->val) return false;
//         pre = root;
//         return isValid(root->right, pre);
//     }
// };
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode* pre = NULL;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(pre && root->val <= pre->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};
// @lc code=end

