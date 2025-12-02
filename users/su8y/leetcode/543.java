/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int max; // maxlength 를 구해주는것으로 left deps + right depts다 .
    public int dfs(TreeNode node){
        if(node == null) return 0; //leaf 노드에 도착하면 그냥 깊이는 0
        int L = dfs(node.left);
        int R = dfs(node.right);
        if(L + R > max) max = L + R;

        return Math.max(L,R) + 1; // deps 를 1 증가시켜줌

    }
    public int diameterOfBinaryTree(TreeNode root) {
        max = 0;
        dfs(root);
        return max;
    }
}