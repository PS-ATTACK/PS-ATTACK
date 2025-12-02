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
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        preorder(root, v);
        for(int i=0;i<v.size()-1;i++){
            if(v[i] >= v[i+1]) return false;
        }
        return true;
    }
private:
void preorder(TreeNode* root, vector<int>& v){
    if(!root) return;
    preorder(root->left, v);
    v.push_back(root->val);
    preorder(root->right, v);
}
};