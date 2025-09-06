#include <iostream>
#include <vector>


class Solution {
    public:
        int minCostClimbingStairs(std::vector<int> &cost) {

            if(cost.size() == 0){
                return 0;
            }

            if(cost.size() == 1){
                return cost[0];
            }

            int returned_value = 0;
            std::vector<int> dp(cost.size(), 0);
            dp[0] = cost[0];
            dp[1] = cost[1];

            for(int i = 2; i <= (int)cost.size() - 1; i++){
                dp[i] = std::min(dp[i - 1], dp[i - 2]) + cost[i];

            }

            returned_value = std::min(dp[cost.size() - 1], dp[cost.size() - 2]);
            return returned_value;
        }
};


int main(void){
    std::cout << std::endl;

    Solution s1;

    std::vector<int> check = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int result = s1.minCostClimbingStairs(check);

    std::cout << "Result is: " << result << std::endl;


    std::cout << std::endl;
    return 0;
}