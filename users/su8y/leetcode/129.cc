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
    /*
    129. Sum Root to Leaf Numbers
    https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=study-plan-v2&envId=top-interview-150

        root 가 0일때를 0이 나올수 있는 것을 생각한다. string으로 처리하기 보다는 sum을 넘겨준다.

    */
public:
    vector<string> v;
    int sumNumbers(TreeNode* root) {
        int ret = 0;

        dfs(root, ""); // setup v

        for(auto& x: v){
            // reverse( x.begin(), x.end() ) ;
            ret += stoi(x);
        }
        return ret;
    }
    void dfs(TreeNode* root, string sum){
        if( !root ) return;
        bool isLeaf = !root->right && !root->left;
        if(isLeaf)  {
            v.push_back(sum + to_string(root->val) );
            return;
        }
        
        dfs(root->left, sum + to_string(root->val) );
        dfs(root->right, sum + to_string(root->val) );
    }
};