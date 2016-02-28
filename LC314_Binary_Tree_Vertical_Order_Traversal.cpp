


/*
314. Binary Tree Vertical Order Traversal

https://leetcode.com/problems/binary-tree-vertical-order-traversal/

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,20,4,5,2,7],
    _3_
   /   \
  9    20
 / \   / \
4   5 2   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,5,2],
  [20],
  [7]
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        int min = 0;
        int max = 0;
        unordered_map<int,vector<int>> mymap;
        queue<TreeNode*> myq;
        queue<int> myqScore;
        vector<vector<int>> ret;
        if(root == NULL){
            return ret;
        }
        myq.push(root);
        myqScore.push(0);
        while(!myq.empty()){
            TreeNode* front = myq.front();
            int frontScore = myqScore.front();
            
            if(mymap.find(frontScore) == mymap.end()){
                vector<int> vec;
                vec.push_back(front->val);
                mymap[frontScore] = vec;
            }else{
                mymap[frontScore].push_back(front->val);
            }
            
            if(front->left != NULL){
                myq.push(front->left);
                myqScore.push(frontScore-1);
                if(frontScore-1 <min){
                    min = frontScore-1;
                }
            }
            if(front->right != NULL){
                myq.push(front->right); 
                myqScore.push(frontScore+1);
                if(frontScore+1 >max){
                    max = frontScore+1;
                }
            }
            myq.pop();
            myqScore.pop();
        }
        for(int i = min; i <=max;i++){
            if(mymap.find(i)!=mymap.end()){
                ret.push_back(mymap[i]);
            }
            
        }
        cout << min << " " <<max;
        return ret;
    }
    
};
    