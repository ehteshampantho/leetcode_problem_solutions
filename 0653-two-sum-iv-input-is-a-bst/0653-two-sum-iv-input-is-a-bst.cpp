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
// #include<bits/stdc++.h>
class Solution {
public:
    
    vector<int> v;
    void traverse(TreeNode * root){
        if(root == NULL) return;
        if(root) v.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        traverse(root);
        bool flag = false;
        for(int val: v){
            cout<< val << " ";
        }
        cout<<endl;
        for(int i=0;i < v.size()-1;i++){
            for(int j=i+1; j < v.size(); j++){
                // cout<< v[i] <<" "<< v[j]<< endl;
                if((v[i] + v[j]) == k){
                    flag = true;
                    break;
                }
                // else flag = false;
            }
        }
        return flag;
    }
};