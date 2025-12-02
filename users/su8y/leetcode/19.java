/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int count = 1;
        ListNode head_c=head;

        while((head_c = head_c.next) != null){
            count++;
        }
        if(n == count ) return head.next;
        head_c = head;

        while(head_c  != null){
            if(n == count-1){ // 5
                head_c.next = head_c.next.next;
            }
            n++;
            head_c = head_c.next;
        } 
        return head;
    }
        
}