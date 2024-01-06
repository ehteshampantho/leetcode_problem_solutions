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
    vector<int> v1,v2,v3,v4;
    // FirstTree PreOrder     
    void firstPreOrder(TreeNode * root){
        if(root == NULL){
            v1.push_back(-1);
            return;
        };
        v1.push_back(root->val);
        firstPreOrder(root->left);
        firstPreOrder(root->right);
    }
    // SecondTree PreOrder     
    void secondPreOrder(TreeNode * root){
        if(root == NULL){
            v2.push_back(-1);
            return;
        }
        v2.push_back(root->val);
        secondPreOrder(root->left);
        secondPreOrder(root->right);
    }
    // FirstTree PostOrder
    void firstPostOrder(TreeNode * root){
        if(root == NULL){
            v3.push_back(-1);
            return;
        }
        firstPostOrder(root->left);
        firstPostOrder(root->right);
        v3.push_back(root->val);
    }
    // SecondTree PostOrder
    void secondPostOrder(TreeNode * root){
        if(root == NULL){
            v4.push_back(-1);
            return;
        }
        secondPostOrder(root->left);
        secondPostOrder(root->right);
        v4.push_back(root->val);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        firstPreOrder(p);
        secondPreOrder(q);
        firstPostOrder(p);
        secondPostOrder(q);
        
        if(v1 == v2){
            if(v3 == v4) return true;
            else return false;
        }
        else return false;
    }
};