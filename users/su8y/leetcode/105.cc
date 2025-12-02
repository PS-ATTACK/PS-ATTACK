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
        for(int i=0;i<inorder.size();i++) hashMap[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1);
    }
private:
    unordered_map<int,int> hashMap;
    int p = 0;
    TreeNode* build(vector<int>& preorder, int start, int end){
        if(start > end) return NULL;
        if(p >= preorder.size()) return NULL;

        TreeNode* root = new TreeNode(preorder[p]);
        int inMid = hashMap[preorder[p]];
        p++;

        root->left = build(preorder, start, inMid - 1);
        root->right = build(preorder, inMid + 1, end);
        return root;
    }
};