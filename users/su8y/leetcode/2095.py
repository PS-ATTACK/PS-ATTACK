# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteMiddle(self, head):

        lnode = head; l = 0
        rnode = head; r = 1
        if not head.next:
            return head.next

        while rnode.next:
            rnode = rnode.next
            r += 1
            mid = r // 2
            # lnode next 이ㅏ동
            while l < mid:
                l += 1
                lnode = lnode.next
        removeNode = head

        # remove mid 
        while removeNode  and removeNode.next != lnode:
            removeNode = removeNode.next

        if removeNode and lnode:
            removeNode.next = lnode.next

        return head

        