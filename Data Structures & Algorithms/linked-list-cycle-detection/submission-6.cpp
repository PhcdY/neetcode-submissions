class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Kiểm tra an toàn trước khi gán con trỏ
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        // Cần có dấu '*' để khai báo con trỏ
        ListNode *slow = head;
        ListNode *fast = head;

        // Đảo ngược thứ tự kiểm tra trong while
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast == slow) {
                return true;
            }
        }
        
        return false;
    }
};