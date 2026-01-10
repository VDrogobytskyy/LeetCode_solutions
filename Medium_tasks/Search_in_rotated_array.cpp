#include <iostream>
#include <vector>

class Solution {
    public:
        int search(std::vector<int> &nums, int target) {
            int returned_value = -1;

            if(!nums.empty()){
                for(int i = 0; i != (nums.size() / 2) + 1; i++){
                    int *left = &nums[i];
                    int *right = &nums[(nums.size() - 1) - i];

                    if(*left == target){
                        returned_value = i;
                        return returned_value;

                    }else if(*right == target){
                        returned_value = (nums.size() - 1) - i;
                        return returned_value;

                    }else{
                        continue;
                    }
                }
            }
            return returned_value;
        }
};


int main(void){
    std::cout << std::endl;

    Solution s;
    std::vector<int> check_vec = {4,5,6,7,0,1,2};
    int check_int = 0;

    // std::vector<int> check_vec = {1};
    // int check_int = 1;

    int result = s.search(check_vec, check_int);

    std::cout << result << std::endl;


    std::cout << std::endl;
    return 0;
}