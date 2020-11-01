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
    int getDecimalValue(ListNode* head) {
        // string n;
        // int i, l = 0;
        // ListNode *t = head;
        // while (t)
        // {
        //     n += to_string(t -> val);
        //     t = t -> next;
        //     ++l;
        // }
        // int N = 0, p = 1;
        // for (i = l - 1; i >= 0; --i)
        // {
        //     N += (n[i] - 48) * p;
        //     p <<= 1;
        // }
        // return N;
        int p = 1, i, N = 0;
        ListNode *t = head;
        while (t)
        {
            p <<= 1;
            t = t -> next;
        }
        p >>= 1;
        t = head;
        while (t)
        {
            N += t -> val * p;
            p >>= 1;
            t = t -> next;
        }
        return N;
    }
};