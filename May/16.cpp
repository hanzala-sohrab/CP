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
    ListNode* oddEvenList(ListNode* head) {
        if (!head)
            return head;
        ListNode *odd=head,*even=head->next,*E=even;
        while (1)
        {
            if (odd && even)
            {
                odd->next=even->next;
                if (even->next)
                    even->next=even->next->next;
                if (!odd->next)
                {
                    odd->next=E;
                    break;
                }
                odd=odd->next;
                even=even->next;
            }
            else
            {
                odd->next=E;
                break;
            }
        }
        return head;
    }
};
