#include <iostream>
#include <vector>

class Solution {
    public:
        int removeElement(std::vector<int> &nums, int val) {
            std::vector<int> temp;
            for(int i = 0; i < nums.size(); i++){
                if (nums[i] != val){
                    temp.push_back(nums[i]);
                }
            }   
            nums = temp;
            return temp.size();
        }
};



int main(void){
    std::cout << std::endl;
    Solution s1;
    std::vector<int> check = {1, 2, 3, 3, 3, 3, 5};
    int result = s1.removeElement(check, 3);

    std::cout << "len is: " << result << std::endl;


    std::cout << std::endl;
    return 0;
}