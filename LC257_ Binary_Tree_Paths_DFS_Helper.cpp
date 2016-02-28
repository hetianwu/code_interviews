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







void dfs(vector<string> &final,vector<string> &inter, TreeNode* node){
    if(node->left == NULL && node->right == NULL){
        for(int i = 0;i<inter.size();i++){
                final.push_back(inter[i]);
        }
    }else{
        vector<string>left;
        vector<string>right;
        for(int i = 0;i<inter.size();i++){
            if(node->left != NULL){
                string str_left = inter[i]+ "->"+ to_string(node->left->val);  
                left.push_back(str_left);
            }
            if(node->right != NULL){
                    string str_right = inter[i]+ "->"+ to_string(node->right->val);
                    right.push_back(str_right);
                }
            }
            
        if(node->left !=NULL){
            dfs(final,left,node->left);
        }
        if(node->right !=NULL){
            dfs(final,right,node->right);
        }
            
           
    }
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ret;
    if(root == NULL){
        return ret;
    }
    vector<string> inter;
    inter.push_back(to_string(root->val));
    dfs(ret,inter,root);
    return ret;
        
}