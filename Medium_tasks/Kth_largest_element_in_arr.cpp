#include <iostream>
#include <vector>
#include <queue>

class Solution {
    public:
        int findKthLargest(std::vector<int> &nums, int k) {
            std::priority_queue<int> pri_q;

            for(int i = 0; i != (int)nums.size(); i++){
                pri_q.push(nums[i]);
            }

            for(int y = 0; y < k - 1; y++){
                pri_q.pop();
            }

            return pri_q.top();
        }
};


int main(void){
    std::cout << std::endl;

    Solution s;

    std::vector<int> check_vec = {3,2,3,1,2,4,5,5,6};
    int check_k = 4;

    int result = s.findKthLargest(check_vec, check_k);
    std::cout << result << std::endl;

    std::cout << std::endl;
    return 0;
}