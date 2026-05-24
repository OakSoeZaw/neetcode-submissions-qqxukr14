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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode* current = p;
        TreeNode* current2 = q;
        bool res1 = false;
        bool res2 = false;

        if(current == nullptr && current2 == nullptr){
            return true;
        }
        if(current == nullptr || current2 == nullptr){
            return false;
        }


        if(current->val == current2->val){
            res1 = isSameTree(current->left, current2->left);
            res2 = isSameTree(current->right, current2->right);
        }else{
            return false;
        }
        return res1 && res2;
    }
};
