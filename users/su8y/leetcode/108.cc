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
    TreeNode* traverse(vector<int>& nums, int lo, int hi){
        if(lo > hi) return nullptr;
        int mid = lo + (hi - lo)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = traverse(nums, lo, mid-1);
        root->right = traverse(nums, mid + 1, hi);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traverse(nums, 0, nums.size() -1);
    }
};