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
    ListNode* reverseList(ListNode* head) {
        ListNode* Curr = head;
        ListNode* Prev= nullptr;
        while(Curr)
        {
            ListNode* temp = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = temp;

        }
        return Prev;
    }
};
