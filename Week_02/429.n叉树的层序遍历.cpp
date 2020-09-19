/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vec;
        vector<int> vec_temp;
        vector<Node*> Nodes;
        vector<Node*> Nodes_temp;
        if (!root) return vec;
        Nodes.push_back(root);
        vec_temp.push_back(root -> val);
        vec.push_back(vec_temp);
        vec_temp.clear();

        while (!Nodes.empty()) {
            for (int i = 0; i < Nodes.size();i++) {
                for (int j = 0;j < Nodes[i]->children.size();j++) {
                    Nodes_temp.push_back(Nodes[i]->children[j]);
                    vec_temp.push_back(Nodes[i]->children[j]->val);
                }
            
            
            }
            Nodes = Nodes_temp;
            if (!vec_temp.empty())
                vec.push_back(vec_temp);
            vec_temp.clear();
            Nodes_temp.clear();             
        }

        return vec;
    }
};
// @lc code=end

