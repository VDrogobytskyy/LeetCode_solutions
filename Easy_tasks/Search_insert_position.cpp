#include <iostream>
#include <vector>

class Solution {
    public:
        int searchInsert(std::vector<int> &nums, int target) {
            
            int returned_value = -1;
            int index_to_insert = -1;

            if(!nums.empty()){

                if(target < nums[0]){
                    index_to_insert = 0;
                }
                for(int i = 0; i < (int)nums.size(); i++){
                    int temp = nums[i];
                    if(nums[i] == target){
                        returned_value = i;
                        return returned_value;
                    }
                    if(target > nums[i]){
                        index_to_insert = i + 1;
                    }

                }

                if(index_to_insert != -1 && returned_value == -1){
                    return index_to_insert;
                }
            }

            return returned_value;
        }
};


int main(void){
    std::cout << std::endl;

    Solution s;
    std::vector<int> check_vec = {1,3,5,6};
    int check_int = 5;

    int result = s.searchInsert(check_vec, check_int);

    std::cout << result << std::endl;


    std::cout << std::endl;
    return 0;
}