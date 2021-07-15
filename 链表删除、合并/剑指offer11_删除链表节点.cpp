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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* phead = dummyNode;
        while (phead->next->val != val) {
            phead = phead->next;
        }
        phead->next = phead->next->next;
        return dummyNode->next;
    }

    ListNode* deleteNode2(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* phead = dummyNode;
        while (phead->val != val) {
            phead = phead->next;
        }
        if (phead->next = nullptr) {
            delete phead;
            return dummyNode->next;
        }
        //尾节点怎么处理？
        phead->val = phead->next->val;
        phead->next = phead->next->next;     
        return dummyNode->next;
    }

    ListNode* deleteNode3(ListNode* head, int val) {
        if(head == nullptr) {
            return nullptr;
        }  
        head -> next = deleteNode(head -> next, val);
        if(head -> val == val) {
            return head -> next;
        }
        return head;
    }
};
