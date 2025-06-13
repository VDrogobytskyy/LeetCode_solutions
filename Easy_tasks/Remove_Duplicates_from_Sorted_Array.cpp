#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


class Solution {
    public:
        int removeDuplicates(std::vector<int> &nums) {
            std::set<int> seen;
            std::vector<int> unique;

            for (int num : nums) {
                if (seen.find(num) == seen.end()) {
                    seen.insert(num);
                    unique.push_back(num);
                }
            }

            nums = unique; 
            return nums.size(); 
        }
};

int main(void){
    std::cout << std::endl;

    Solution s;
    std::vector<int> check = {0,0,1,1,1,2,2,3,3,4};
    int res = s.removeDuplicates(check);

    std::cout << res << std::endl;

    std::cout << std::endl;
    return 0;
}