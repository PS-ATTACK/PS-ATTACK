# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans = []

        def dfs(node, arr):
            if not node: return

            arr.append(node.val)

            if not node.left and not node.right:
                if sum(arr) == targetSum:
                    print(sum(arr), arr)
                    ans.append(arr.copy())
            else:
                dfs(node.left, arr)
                dfs(node.right, arr)
                
            arr.pop()

        dfs(root,[])

        return ans


        