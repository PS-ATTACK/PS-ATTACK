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
    int getMinimumDifference(TreeNode* root) {
        int ret = INT_MAX;
        vector<int> v;

        preorder(root, v);

        for(int i = 0; i< v.size()-1; i++){
            ret = min(ret, abs(v[i]-v[i+1]));
        }
        return ret;
    }
private:
    void preorder(TreeNode* node, vector<int>& v){
        if(!node) return;
        preorder(node->left, v);
        v.push_back(node->val);
        preorder(node->right, v);
    }
};