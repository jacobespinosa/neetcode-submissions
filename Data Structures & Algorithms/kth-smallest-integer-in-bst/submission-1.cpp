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
        vector<int> sortedArray;
        inorder(root, sortedArray);
        return sortedArray[k - 1];
    }
private:
    void inorder(TreeNode* root, vector<int>& sortedArray) {
        if (!root) {
            return;
        }
        inorder(root->left, sortedArray);
        sortedArray.push_back(root->val);
        inorder(root->right, sortedArray);
    }
};
