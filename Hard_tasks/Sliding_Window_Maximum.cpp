#include <iostream>
#include <vector>
#include <queue>

class Solution {
    public:
        std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
            std::vector<int> returned_value;
            std::deque<int> dq;

            if(nums.empty()){
                return {};
            }

            for(int i = 0; i < (int)nums.size(); i++){

                while(!dq.empty() && dq.front() <= i - k){
                    dq.pop_front();
                }

                while(!dq.empty() && nums[dq.back()] < nums[i]){
                    dq.pop_back();
                }

                dq.push_back(i);

                if(i >= k - 1){
                    returned_value.push_back(nums[dq.front()]);
                }
            }
            
            return returned_value;
        }
};

int main(void){
    std::cout << std::endl;

    Solution s;
    std::vector<int> check_vec = {1,3,-1,-3,5,3,6,7};
    int check_k = 3;
    std::vector<int> result_vec = s.maxSlidingWindow(check_vec, check_k);

    for(auto x : result_vec){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}