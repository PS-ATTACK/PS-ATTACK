/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = NULL , *pos = NULL;
        ListNode *left = l1;
        ListNode *right = l2;
        
        while(left && right){
            int sum = left->val + right->val;
            ListNode* val = new ListNode(sum);
            
            if(pos == NULL){
                pos = val;
                newHead = val;
            }else{
                pos->next = val;
                pos = pos->next;
            }
            left = left->next;
            right = right->next;
        }
        while(left){
            pos->next = left;// 노드의 정보를 그대로 넘겨주기때문에 -> val 을 사용하지 않는다.
            pos = pos->next;
            left = left->next;
        }
        while(right){
            pos->next = right;
            pos = pos->next;
            right = right->next;
        }
        pos = newHead;
        while(pos){
            if(pos->val > 9){
                if(pos->next != NULL){
                    pos->next->val += 1;
                }
                else{
                    pos->next = new ListNode(1);
                }
                pos->val = pos->val % 10;
            }
            pos = pos->next;
        
        }
        
        return newHead;
    }
};