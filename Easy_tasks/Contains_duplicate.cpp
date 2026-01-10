#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
    public:
        bool containsDuplicate(std::vector<int> &nums) {
        std::unordered_set<int> seen;

        for(int x : nums){
            if(seen.count(x)){
                return true;  
            }
            seen.insert(x);
        }
        return false;
    }
        
};

int main(void){
    std::cout << std::endl;

    Solution s;

    std::vector<int> test_ans = {1,1,1,3,3,4,3,2,4,2};
    bool result = s.containsDuplicate(test_ans);

    std::cout << result << std::endl;

    std::cout << std::endl;
    return 0;
}