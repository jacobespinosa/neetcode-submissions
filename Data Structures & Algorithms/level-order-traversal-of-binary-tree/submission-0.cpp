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
        vector<vector<int>> result;
        queue<TreeNode*> queue;
        if (root) queue.push(root);

        while(queue.size() > 0) {
            int length = queue.size();
            vector<int> sublist;

            for(int i = 0; i < length; i++) {
                TreeNode* curr = queue.front();
                if (curr->left) {
                    queue.push(curr->left);
                }
                if (curr->right) {
                    queue.push(curr->right);
                }
                sublist.push_back(curr->val);
                queue.pop();
            }
            result.push_back(sublist);
        }
        return result;
    }
};
