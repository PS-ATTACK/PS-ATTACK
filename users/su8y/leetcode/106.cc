/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            hashMap[inorder[i]] = i;
        p = postorder.size() - 1;
        return build(0, postorder.size() - 1, postorder);
    }

private:
    int p;
    unordered_map<int, int> hashMap;

    TreeNode* build(int lo, int hi, vector<int>& postorder) {

        if (lo > hi)
            return NULL;
        if (p < 0)
            return NULL;

        int post_val = postorder[p];
        p--;
        TreeNode* root = new TreeNode(post_val);
        int inMid = hashMap[post_val];
        root->right = build(inMid + 1, hi, postorder);
        root->left = build(lo, inMid - 1, postorder);

        return root;
    }
};