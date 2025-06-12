#include <iostream>
#include <vector>
#include <algorithm>



class Solution {
    public:
        int maxAdjacentDistance(std::vector<int> &nums) {
            
            int len = (int)nums.size();
            int max_dist = std::abs(nums[len - 1] - nums[0]);
            for(int i = 0; i < len; i++){
                if(i + 1 != len){
                    if(std::abs(nums[i] - nums[i + 1]) > max_dist){
                     max_dist = std::abs(nums[i] - nums[i + 1]);
                    }
                }
            }

            return max_dist;
        }
};

int main(void){
    std::cout << std::endl;
    Solution s;

    std::vector<int> check = {1,2,4};

    int res = s.maxAdjacentDistance(check);
    std::cout << res << std::endl;

    std::cout << std::endl;
    return 0;
}