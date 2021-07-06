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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        ListNode* cur = head;
        ListNode* phead1 = dummy1;
        ListNode* phead2 = dummy2;
        while (cur != nullptr) {
            if (cur->val < x) {
                phead1->next = cur;
                phead1 = phead1->next;
            }
            else {
                phead2->next = cur;
                phead2 = phead2->next;
            }
            cur = cur->next;
        }
        phead1->next = dummy2->next;
        phead2->next = nullptr;
        return dummy1->next;
    }
};
