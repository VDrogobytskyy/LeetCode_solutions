#include <iostream>
#include <vector>

class Solution {
    public:
        void moveZeroes(std::vector<int> &nums) {
            int num_position = 0;
            for(int i = 0; i < (int)nums.size(); i++){
                if(nums[i] != 0){
                    nums[num_position] = nums[i];
                    num_position++;
                }
            }
            for(int i = num_position; i < (int)nums.size(); i++){
                nums[i] = 0;
            }

        }
};


int main(void){
    std::cout << std::endl;

    Solution s;
    std::vector<int> check_vec = {0,1,0,3,12};
    s.moveZeroes(check_vec);

    std::cout << std::endl;
    return 0;
}