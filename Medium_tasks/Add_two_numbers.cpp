#include <iostream>





struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *returned_value = new ListNode(0);
            ListNode *current = returned_value;
            int transfer = 0;

            while (l1 != nullptr || l2 != nullptr || transfer != 0){
                int l1_num = 0, l2_num = 0;
                if(l1 != nullptr){
                    l1_num = l1->val;
                }
                if(l2 != nullptr){
                    l2_num = l2->val;
                }
                int sum = l1_num + l2_num + transfer;
                int num_to_insert = sum % 10;
                transfer = sum / 10;

                current->next = new ListNode(num_to_insert);
                current = current->next;

                if(l1 != nullptr){
                    l1 = l1->next;
                }

                if(l2 != nullptr){
                    l2 = l2->next;
                }
            }
            return returned_value->next;
        }
};

int main(void){
    std::cout << std::endl;

    Solution s;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = s.addTwoNumbers(l1, l2);

    ListNode* curr = result;
    while(curr != nullptr){
        std::cout << curr->val << " ";
        curr = curr->next;
    }


    std::cout << std::endl;
    return 0;
}