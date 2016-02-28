
/*

257. Binary Tree Paths

https://leetcode.com/problems/binary-tree-paths/

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]


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

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ret;
    if(root == NULL){
            return ret;
    }
    // obtain all paths go through left and right children.
    vector<string> left_paths = binaryTreePaths(root->left);
    vector<string> right_paths = binaryTreePaths(root->right);
    
    ret.insert(ret.end(),left_paths.begin(),left_paths.end());
    ret.insert(ret.end(),right_paths.begin(),right_paths.end());
    // if root itself is a leaf then just return root
    // otherwise concatenate root to the front of each path 
    if(ret.size() == 0){
            ret.push_back(to_string(root->val));
    }else{
        for(int i = 0;i<ret.size();i++){
            ret[i] = to_string(root->val)+"->"+ret[i];
        }
    }
    return ret;
        
        
        
}