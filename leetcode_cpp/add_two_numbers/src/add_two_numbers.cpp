#include <iostream>

struct ListNode {
    int val;
    ListNode*next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode*next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p_list1 = l1;
        ListNode* p_list2 = l2;
        ListNode* p_list_sum = NULL;
        ListNode* p_temp = NULL;
        int val_temp = 0;
        bool is_remember = false;
        
        while (p_list1 != NULL || p_list2 != NULL || is_remember)
        {
            val_temp = 0;
            if (p_list1 != NULL) {
                val_temp += p_list1->val;
                p_list1 = p_list1->next;
            }
            if (p_list2 != NULL) {
                val_temp += p_list2->val;
                p_list2 = p_list2->next;
            }

            if (is_remember)            val_temp += 1;

            if (val_temp > 9) {
                is_remember = true;
                val_temp -= 10;
            }
            else {
                is_remember = false;
            }

            ListNode* node = new ListNode(val_temp);
            if (p_list_sum == NULL) {
                p_list_sum = node;
            }
            else {
                p_temp->next = node;
            }
            p_temp = node;
        }
        return p_list_sum;
    }
};

void main()
{
    Solution solution;

    ListNode* L1_1 = new ListNode(9);
    ListNode* L1_2 = new ListNode(9, L1_1);
    ListNode* L1_3 = new ListNode(9, L1_2);
    ListNode* L1_4 = new ListNode(9, L1_3);
    ListNode* L1_5 = new ListNode(9, L1_4);
    ListNode* L1_6 = new ListNode(9, L1_5);
    ListNode* L1_7 = new ListNode(9, L1_6);

    ListNode* L2_1 = new ListNode(9);
    ListNode* L2_2 = new ListNode(9, L2_1);
    ListNode* L2_3 = new ListNode(9, L2_2);
    ListNode* L2_4 = new ListNode(9, L2_3);

    ListNode* list_sum = solution.addTwoNumbers(L1_7, L2_4);
}