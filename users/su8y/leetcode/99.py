# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        arr = []
        idx = 0
        def dfs(x):
            if not x: return
            dfs(x.left)
            arr.append(x.val)
            dfs(x.right)
        
        def insertDfsPostorder(x):
            nonlocal idx
            if not x: return
            insertDfsPostorder(x.left)
            x.val = arr[idx]
            idx += 1
            insertDfsPostorder(x.right)

        dfs(root) # constructure arr
        arr.sort() # sorting arr
        insertDfsPostorder(root) # insert tree search[post-order]