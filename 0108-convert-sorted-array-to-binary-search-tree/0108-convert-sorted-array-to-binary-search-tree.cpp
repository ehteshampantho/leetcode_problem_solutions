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
    
    TreeNode * convert_arr_BST(vector<int> v,int n,int l,int r){
        if(l>r) return NULL;
        int mid = (l+r)/2;
        TreeNode * root = new TreeNode(v[mid]);
        TreeNode * myLeft = convert_arr_BST(v,n,l,mid-1);
        TreeNode * myRight = convert_arr_BST(v,n,mid+1,r);
        root->left = myLeft;
        root->right = myRight;
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * root = convert_arr_BST(nums,nums.size(),0,nums.size()-1);
        return root;
    }
};