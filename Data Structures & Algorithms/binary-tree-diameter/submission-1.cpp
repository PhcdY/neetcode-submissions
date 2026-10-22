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
    int maxDepth(TreeNode* root) {

        if(root==nullptr){
            return 0;
        }
        
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return max(l,r)+1;
    
    }


    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int dia = rightDepth + leftDepth;

        return max(dia,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};
