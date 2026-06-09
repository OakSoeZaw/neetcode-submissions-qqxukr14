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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<vector<int>> currentLeft;
        vector<vector<int>> currentRight;
        if(root == nullptr){
            return res;
        }
        
        currentLeft = levelOrder(root->left);
        currentRight = levelOrder(root->right);
        res.push_back({root->val});
        
        int n = max(currentRight.size(), currentLeft.size());

        for(int i = 0; i< n; i++){
            vector<int> merged;
            if(i < currentLeft.size()){
                merged.insert(merged.end(), currentLeft[i].begin(), currentLeft[i].end());
            }
            if(i < currentRight.size()){
                merged.insert(merged.end(), currentRight[i].begin(), currentRight[i].end());
            }

            res.push_back(merged);
        }
        
    
        return res;
    }
};
