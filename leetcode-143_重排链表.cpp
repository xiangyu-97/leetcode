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
    void reorderList(ListNode* head) {
        if ( head == nullptr || head->next == nullptr || head->next->next == nullptr ) return;
        vector<ListNode*> orders;
        ListNode* trarNode = head;
        ListNode* phead = new ListNode(-1);
        while ( trarNode != nullptr ) {
            orders.push_back(trarNode);
            trarNode = trarNode->next;
        }
        int left = 0;
        int right = orders.size() - 1;
        while ( left <= right ) {
            phead->next = orders[left];
            phead = phead->next;
            left++;        
            //if ( left == right ) break;
            phead->next = orders[right];
            phead = phead->next;
            right--;
        }
        phead->next = nullptr;
    }

    /* 反转后半段链表并合并（待完善）*/
    void reorderList2(ListNode* head) {
        if ( head == nullptr || head->next == nullptr ) return;
        ListNode* mNode = middleNode(head);
        ListNode* addNode2 = reverseList(mNode->next);
        mNode->next = nullptr;
        ListNode* addNode1 = head;
        addNode1 = mergeList(addNode1,addNode2);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while ( fast->next != nullptr && fast->next->next != nullptr ) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
	    ListNode* phead = head;  
	    ListNode* pre = nullptr;  
	    while(phead != nullptr){
		    ListNode* temp = pre;
		    pre = phead;
		    phead = phead->next;
		    pre->next = temp;  
	    }
	    return pre; 
    }

    ListNode* mergeList(ListNode* addNode1,ListNode* addNode2) {
        ListNode* pAddNode1 = addNode1;
        ListNode* pAddNode2 = addNode2;
        while ( pAddNode1 != nullptr && pAddNode2 != nullptr ) {
            ListNode* temp1 = pAddNode1;
            ListNode* temp2 = pAddNode2;
            pAddNode1->next = pAddNode2;
            pAddNode2->next = temp1->next;
            pAddNode1 = temp1->next;
            pAddNode2 = temp2->next;
        }
        if ( pAddNode1 != nullptr ) {
            pAddNode2->next = pAddNode1;
        }
        return addNode1;
    }
};
