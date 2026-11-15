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
        vector<int> btsArray;
        sortedBTS(root, btsArray);
        return btsArray[k - 1];
    }
private:
    void sortedBTS(TreeNode* root, vector<int>& sortedArray) {
        if (!root) {
            return;
        }
        sortedBTS(root->left, sortedArray);
        sortedArray.push_back(root->val);
        sortedBTS(root->right, sortedArray);
    }
};
