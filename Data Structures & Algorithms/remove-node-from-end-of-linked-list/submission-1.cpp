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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=0;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev = new ListNode(0);

        if (head->next==nullptr){
            return nullptr;
        }

        for(int i=1;i<n;i++){
            fast=fast->next;
        }

        while(fast->next!=nullptr){
            fast=fast->next;
            prev = slow;
            slow=slow->next;
        }

        if(slow!=head){
            prev->next = slow->next;
        }
        
        else{
            head = head->next;
        }
        
        return head;

    }
};
