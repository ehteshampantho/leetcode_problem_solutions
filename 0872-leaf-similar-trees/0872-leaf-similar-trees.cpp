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
    vector<int> v1,v2;
    void firstTree(TreeNode* root){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            v1.push_back(root->val);
        }
        firstTree(root->left);
        firstTree(root->right);
    }
    void secondTree(TreeNode* root){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            v2.push_back(root->val);
        }
        secondTree(root->left);
        secondTree(root->right);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        firstTree(root1);
        secondTree(root2);
        if(v1 == v2) return true;
        else return false;
    }
};