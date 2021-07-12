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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        int count = 1;
        ListNode *countNode = head;
        while (countNode->next != nullptr) {
            countNode = countNode->next;
            count++;
        }
        int delay = k % count; 
        if (delay == 0) return head;

        ListNode *ptail = head, *tail = head;
        while (delay  > 0) {
            tail = tail->next;
            delay--;
        }

        while (tail->next != nullptr) {
            ptail = ptail->next;
            tail  = tail->next;
        }
        ListNode* phead = ptail->next;
        ptail->next = nullptr;
        tail->next = head;
        return phead;
    }
};
