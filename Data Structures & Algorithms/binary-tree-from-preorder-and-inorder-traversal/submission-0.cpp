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
        TreeNode *root = nullptr;
        if (preorder.empty() || inorder.empty()){
            return nullptr;
        }

        int rootVal = preorder.front();
        root = new TreeNode(rootVal);
        auto mid = find(inorder.begin(), inorder.end(), rootVal);
        auto index = mid - inorder.begin();
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() +
        index + 1);
        vector<int> rightPre(preorder.begin() + index + 1, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + index + 1);
        vector<int> rightIn(inorder.begin()+ index +1, inorder.end());
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);

        return root;
    }
};
