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
    int ans = INT_MIN;
    int dfs(TreeNode* root){
        if(root == nullptr)
            return 0;
        int leftmax = max(0 , dfs(root->left));
        int rightmax = max(0 , dfs(root->right));
        int currpath = leftmax + rightmax + root->val;

        ans = max(ans , currpath);
        return root->val + max(leftmax , rightmax);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
