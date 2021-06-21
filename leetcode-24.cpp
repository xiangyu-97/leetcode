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
    /* 递归 */
    ListNode* swapPairs(ListNode* head) {
        if ( head == nullptr) {
            swapPairs(head)
        }
    }
    
    /* 迭代 */
    ListNode* swapPairs2(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        ListNode* swap1 = head;
        ListNode* swap2 = head->next;
        while ( swap1 != nullptr &&  swap2 != nullptr ) {
            swap1 -> next = swap2 -> next;
            swap2 -> next = swap1;
            pre -> next = swap2;
            pre = swap1;
            swap1 = pre -> next;
            if (swap1 != nullptr) {
                swap2 = pre -> next -> next; 
            }
            else {
                break;
            }
        }
        return dummy -> next;
        delete dummy;
    }
};
