/*
102. Binary Tree Level Order Traversal

https://leetcode.com/problems/binary-tree-level-order-traversal/

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL){
            return ret;
        }
        queue<TreeNode*> myq;
        queue<int> myqDepth;
        myq.push(root);
        myqDepth.push(0);
        int counter = -1;
        int curDepth = -1;
        while(!myq.empty()){
            TreeNode* front = myq.front();
            int depth = myqDepth.front();
            if(depth>curDepth){
                vector<int> vec;
                ret.push_back(vec);
                counter++;
                curDepth = depth;
            }
            ret[counter].push_back(front->val);
            
            if(front->left != NULL){
                myq.push(front->left);
                myqDepth.push(depth+1);
            }
            if(front->right != NULL){
                myq.push(front->right);
                myqDepth.push(depth+1);
            }
            myq.pop();
            myqDepth.pop();
            
        }
    }
};