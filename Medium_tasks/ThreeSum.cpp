#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    public:
        std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
            std::vector<std::vector<int>> result_holder;

            std::sort(nums.begin(), nums.end());
            int target = 0;

            for(int i = 0; i < (int)nums.size() - 2; i++){
                if (i > 0 && nums[i] == nums[i-1]) continue;
                int *ptr = &nums[i + 1];
                int *end_ptr = &nums[nums.size() - 1];
                
                while(ptr != end_ptr){
                    if(nums[i] + (*ptr) + (*end_ptr) == target){
                        result_holder.push_back( { nums[i], *ptr, *end_ptr } );
                        int last_left = *ptr;
                        int last_right = *end_ptr;

                        while(ptr < end_ptr && *ptr == last_left) ptr++;
                        while(ptr < end_ptr && *end_ptr == last_right) end_ptr--;

                    }else if(nums[i] + (*ptr) + (*end_ptr) < target){
                        ptr++;
                    }else{
                        end_ptr--;
                    }
                }

            }
            return result_holder;
        }
};


int main(void){
    std::cout << std::endl;
    
    Solution s1;
    std::vector<int> checking = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result = s1.threeSum(checking);

    for(int i = 0; i < (int)result.size(); i++){
        for(int j = 0; j < (int)result[i].size(); j++){
            std::cout << result[i][j] << " "; 
        }
        std::cout << std::endl;
    }


    std::cout << std::endl;
    return 0;
}