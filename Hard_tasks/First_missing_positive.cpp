#include <iostream>
#include <vector>


class Solution {
    public:
        int firstMissingPositive(std::vector<int> &nums) {

            for(int i = 0; i < (int)nums.size(); i++){
                while(nums[i] >= 1 && nums[i] <= (int)nums.size() && nums[nums[i] - 1] != nums[i]){
                    std::swap(nums[i], nums[nums[i] - 1]);
                }
            }

            for(int i = 0; i < (int)nums.size(); i++){
                if(nums[i] != i + 1){
                    return i + 1;
                }
            }

            return (int)nums.size() + 1;
        }
};


int main(void){
    std::cout << std::endl;

    Solution s;
    std::vector<int> check_vec = {3,4,-1,1};
    int result = s.firstMissingPositive(check_vec);

    std::cout << result << std::endl;

    std::cout << std::endl;
    return 0;
}