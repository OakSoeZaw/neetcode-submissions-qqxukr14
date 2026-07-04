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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> myStack;
        int n=0;
        TreeNode* curr = root;

        while (!myStack.empty() || curr != nullptr){
            while (curr != nullptr){
                myStack.push(curr);
                curr = curr->left;
            }

            curr = myStack.top();
            myStack.pop();
            n += 1;
            if (n==k){
                return curr->val;
            }
            curr = curr->right;

        }
        return -1;
    }
};
