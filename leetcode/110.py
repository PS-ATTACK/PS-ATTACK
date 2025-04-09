# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def traverse(x):
            if not x: 
                return [True, 0]
            l_balance, l_height  = traverse(x.left)
            r_balance, r_height = traverse(x.right)

            isBalance = l_balance and r_balance and abs(l_height - r_height) <= 1
            return [isBalance, max(l_height, r_height) + 1]
        return traverse(root)[0]
