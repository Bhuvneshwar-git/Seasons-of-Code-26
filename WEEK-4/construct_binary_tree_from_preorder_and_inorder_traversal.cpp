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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return make(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* make(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        TreeNode* root = new TreeNode(preorder[ps]);
        int count = 0;
        int i = is;
        while (i <= ie && inorder[i] != preorder[ps]) {
            i++;
            count++;
        }
        TreeNode* left = count == 0 ? nullptr : make(preorder, inorder, ps+1, ps+count, is, is+count-1);
        int count1 = ie - i;
        TreeNode* right = count1 == 0 ? nullptr : make(preorder, inorder, ps+count+1, pe, i+1, ie);
        root -> left = left;
        root -> right = right;
        return root;
        

    }
};