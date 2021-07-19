/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr) return head;
        int count = 1;
        ListNode *fast = head;
        ListNode *slow = head;
        while(count < k) {
            fast = fast->next;
            count++;
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        } 
        return slow;
    }
};
