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
    ListNode* getmid(ListNode *head){
        ListNode* n = head;
        ListNode* n2 = head->next;
        while(n2 && n2->next){
            n= n->next;
            n2= n2->next->next;
        }
        return n;
    }
    ListNode* divide(ListNode* root) {
        if (!root || !root->next)
            return root;

        ListNode* left = root;
        ListNode* tmp = left;
        ListNode* mid = getmid(root);
        
        ListNode* right = mid->next;
        mid->next = NULL;

        left = divide(left);
        right = divide(right);

        return merge(left, right);
    }
    ListNode* merge(ListNode* a, ListNode* b) {
        if (a == NULL) return b;
        if (b == NULL) return a;

        ListNode* newList = new ListNode(0);
        ListNode* temp = newList;

        while (a != NULL && b != NULL) {
            if (a->val < b->val) {
                temp->next = a;
                temp = a;
                a = a->next;
            } else {
                temp->next = b;
                temp = b;
                b = b->next;
            }
        }
        while (a != nullptr) {
            temp->next = a;
            temp = a;
            a = a->next;
        }
        while (b != nullptr) {
            temp->next = b;
            temp = b;
            b = b->next;
        }

        return newList->next;
    }

    void test() {
        ListNode* a = new ListNode(1);
        a->next = new ListNode(3);
        ListNode* b = new ListNode(2);
        b->next = new ListNode(4);
        ListNode* mergeTest = merge(a, b);
    }

public:
    ListNode* sortList(ListNode* head) {
        return divide(head);
    }
};