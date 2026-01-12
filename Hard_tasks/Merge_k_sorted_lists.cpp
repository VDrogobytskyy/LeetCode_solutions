#include <iostream>
#include <vector>
#include <queue>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
    public:
        ListNode* mergeKLists(std::vector<ListNode*> &lists) {
            ListNode returned_value;
            ListNode *current = &returned_value;

            std::priority_queue<int, std::vector<int>, std::greater<int>> pr_q_of_Nodes;

            for(auto Listnodes_Item : lists){
                while (Listnodes_Item != nullptr){
                    pr_q_of_Nodes.push(Listnodes_Item->val);
                    Listnodes_Item = Listnodes_Item->next;
                }
                
            }

            while(!pr_q_of_Nodes.empty()){
                current->next = new ListNode(pr_q_of_Nodes.top());
                pr_q_of_Nodes.pop();
                current = current->next;
            }

            return returned_value.next;

        }
};



int main(void){
    std::cout << std::endl;

    Solution s;

    ListNode *ln1 = new ListNode(1);
    ln1->next = new ListNode(4);
    ln1->next->next = new ListNode(5);

    ListNode *ln2 = new ListNode(1);
    ln2->next = new ListNode(3);
    ln2->next->next = new ListNode(4);

    ListNode *ln3 = new ListNode(2);
    ln3->next = new ListNode(6);

    std::vector<ListNode*> check_vec = {ln1, ln2, ln3};

    ListNode *result = s.mergeKLists(check_vec);

    while(result != nullptr){
        std::cout << result->val << std::endl;
        result = result->next;
    }


    std::cout << std::endl;
    return 0;
}