#include <iostream>
#include <vector>



class Solution {
    public:
        int dominantIndex(std::vector<int> &nums) {
            int max_el = *std::max_element(nums.begin(), nums.end());
            auto index = std::max_element(nums.begin(), nums.end());
            int i = index - nums.begin();

            for(auto x : nums){

                if(x == max_el){
                    continue;
                }
                if((x * 2) <= max_el){
                    continue;
                }else{
                    return -1;
                }
            }

            return i;
        }
};



int main(void){
    std::cout << std::endl;

    Solution s;
    std::vector<int> test_vec = {3,6,1,0};
    int result = s.dominantIndex(test_vec);

    std::cout << result << std::endl;

    std::cout << std::endl;
    return 0;
}