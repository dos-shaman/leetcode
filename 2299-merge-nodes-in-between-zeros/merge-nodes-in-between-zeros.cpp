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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* p1 = head->next;
        ListNode* newHead = nullptr;
        ListNode* p2;
        int value = 0;

        while (p1) {
            if (p1->val == 0) {
                auto temp = new ListNode(value);
                value = 0;
                if (!newHead) {
                    newHead = temp;
                    p2 = newHead;
                } else {
                    p2->next = temp; 
                    p2 = p2->next;
                }
            } else {
                value += p1->val;
            }
            ListNode* temp = p1;
            p1 = p1->next;
            delete temp;
        }

        return newHead;
    }
};