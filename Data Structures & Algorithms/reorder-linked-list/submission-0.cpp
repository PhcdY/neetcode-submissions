class Solution {
public:
    void reorderList(ListNode* head) { // Sửa thành ListNode*
        // Bắt edge case: rỗng hoặc chỉ có 1-2 node thì không cần đổi
        if (!head || !head->next || !head->next->next) return;

        // 1. Tìm điểm giữa
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 2. Cắt đôi và Đảo ngược nửa sau
        ListNode* curr = slow->next;
        slow->next = nullptr; // RẤT QUAN TRỌNG: Cắt đứt đuôi của nửa đầu để tránh cycle
        
        ListNode* prev = nullptr;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // 3. Trộn xen kẽ hai nửa
        ListNode* p1 = head;
        ListNode* p2 = prev; // prev lúc này đang là head của nửa sau đã đảo

        while (p2 != nullptr) {
            // Giữ lại node tiếp theo của cả 2 nửa
            ListNode* tmp1 = p1->next;
            ListNode* tmp2 = p2->next;

            // Nối chéo
            p1->next = p2;
            p2->next = tmp1;

            // Nhích con trỏ đi tiếp
            p1 = tmp1;
            p2 = tmp2;
        }
    }
};