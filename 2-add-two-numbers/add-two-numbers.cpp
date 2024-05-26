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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if(l1 == nullptr && l2 == nullptr && carry == 0) return nullptr;
        ListNode* l1v = (l1 != nullptr ? l1 : new ListNode(0));
        ListNode* l2v = (l2 != nullptr ? l2 : new ListNode(0));
        int aux = (l1v->val + l2v->val + carry);
        int v = aux % 10;
        carry = aux / 10;
        ListNode* ans = new ListNode(v, addTwoNumbers(l1v->next, l2v->next, carry));
        return ans;
    }
};