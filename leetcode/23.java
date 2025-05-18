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
    ListNode* mergeAndSort(ListNode* a, ListNode* b){
        if(!a) return b;
        if(!b) return a;
        ListNode* dummy = new ListNode(0);
        ListNode* tmp = dummy;
        while(a && b){
            if(a->val < b->val){
                tmp->next = a;
                a = a->next;
            }else {
                tmp->next = b;
                b = b->next;
            }
            tmp = tmp->next;
        }
        tmp->next = a ? a: b;
        
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return {};
        ListNode* tmp = lists[0];
        for(int i=1; i <lists.size(); i++){
            tmp = mergeAndSort(tmp, lists[i]);
        }
        return tmp;
    }
};