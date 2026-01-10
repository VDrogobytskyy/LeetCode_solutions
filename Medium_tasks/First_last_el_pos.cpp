#include <iostream>
#include <vector>


class Solution {
    public:
        std::vector<int> searchRange(std::vector<int> &nums, int target) {

            if(nums.empty()){
                return {-1, -1};
            }

            int left = find_from_left(nums, target);
            int right = find_from_right(nums, target);

            return {left, right};
        }
        private:
            int find_from_left(std::vector<int> &nums, int target);
            int find_from_right(std::vector<int> &nums, int target);
};

int Solution::find_from_left(std::vector<int> &nums, int target){
    int returned_value = -1;

    for(int i = 0; i < (int)nums.size(); i++){
        if(nums[i] == target){
            return i;
        }
    }

    return returned_value;
}

int Solution::find_from_right(std::vector<int> &nums, int target){
    int returned_value = -1;
    for(int i = nums.size() - 1; i >= 0; i--){
        if(nums[i] == target){
            return i;
        }
    }

    return returned_value;
}

int main(void){
    std::cout << std::endl;

    Solution s;
    std::vector<int> check_vector = {8};
    int targeted_num = 8;
    std::vector<int> res = s.searchRange(check_vector, targeted_num);

    for(auto x : res){
        std::cout << " " <<  x << " ";
    }

    std::cout << std::endl;
    return 0;
}