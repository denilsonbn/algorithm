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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode *t3, *curr3;
        curr3 = t3;

        if (!list1 && !list2) {
            return nullptr;
        }

        curr3 = new ListNode();
        t3 = curr3;

        ListNode *curr1 = list1, *curr2 = list2;

        while(curr1 != nullptr && curr2 != nullptr) {
            int value;

            if (curr1->val < curr2->val) {
                value = curr1->val;
                curr1 = curr1->next;
            }
            else {
                value = curr2->val;
                curr2 = curr2->next;
            }

            curr3->val = value;
            curr3->next = new ListNode();
            curr3 = curr3->next;

        }

        while(curr1 != nullptr) {
            curr3->val = curr1->val;
            curr1 = curr1->next;
            curr3->next = new ListNode();
            curr3 = curr3->next;
        }

        while(curr2 != nullptr) {
            curr3->val = curr2->val;
            curr2 = curr2->next;
            curr3->next = new ListNode();
            curr3 = curr3->next;
        }

        curr3 = nullptr;

        return t3;
    }
};
