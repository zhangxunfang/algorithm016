/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         preorder(root, nodes);
//         return nodes;
//     }
// private:
//     void preorder(TreeNode* root, vector<int>& nodes) {
//         if (root == nullptr) return;
//         nodes.push_back(root -> val);
//         preorder(root -> left, nodes);
//         preorder(root -> right, nodes);
//         return;
//     }
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> nodes;
//         stack<TreeNode*> st;

//         while (root || !st.empty()) {
//             while (root) {
//                 nodes.push_back(root -> val);
//                 st.push(root);
//                 root = root -> left;
//             }

//             root = st.top();
//             st.pop();
//             root = root -> right;
//         }
//         return nodes;
//     }
public:
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> v;
       if(!root) return v;
       TreeNode* temp = root;
       stack<TreeNode*> s;
       s.push(root);
       while (!s.empty()) {
            temp = s.top();
            s.pop();
            v.push_back(temp->val);
            if (temp->right) s.push(temp->right);
            if (temp->left) s.push(temp->left);
        } 
        return v;
    }
            
};
// @lc code=end

