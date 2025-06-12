#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


class Solution {
    public:
        std::vector<int> twoSum(std::vector<int> &nums, int target) {
            std::unordered_map<int, int> seen;

            for (int i = 0; i < nums.size(); ++i) {
                int complement = target - nums[i];
                if (seen.find(complement) != seen.end()) {
                    return {seen[complement], i};
                }
                seen[nums[i]] = i;
            }
            return {};
        }
};

int main(void){
    std::cout << std::endl;

    Solution s;
    std::vector<int> check = {3, 3};

    std::vector<int> res = s.twoSum(check, 6);

    std::cout << res.size() << std::endl;

    for(int el : res){
        std::cout << el << " ";
    }
    
    std::cout << std::endl;
    return 0;
}