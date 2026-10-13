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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* l = list1;
        ListNode* r = list2;
        ListNode dummy; 
        ListNode* cur = &dummy;

        while (l && r) {
            if (l->val <= r->val) {
                cur->next = l;
                l = l->next;
            } else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }

        
        cur->next = l ? l : r;

        return dummy.next;
    }
};
