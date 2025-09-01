#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    public:
        void sortColors(std::vector<int> &nums) {
            int last_twos = nums.size() - 1, zeros_stopper = 0, current = 0;

            while(current <= last_twos){
                if(nums[current] == 0){
                    
                    std::swap(nums[current], nums[zeros_stopper]);
                    zeros_stopper++;
                    current++;

                }else if(nums[current] == 1){
                    current++;

                }else{
                    std::swap(nums[current], nums[last_twos]);
                    last_twos--;
                }
            }

            for(int i = 0; i < (int)nums.size(); i++){
                std::cout << nums[i] << " ";
            }
            std::cout << std::endl;
        }
};

int main(void){
    std::cout << std::endl;
    Solution s1;

    std::vector<int> check = {2, 0, 2, 1, 1, 0};
    
    s1.sortColors(check);
    
    std::cout << std::endl;
    return 0;
}