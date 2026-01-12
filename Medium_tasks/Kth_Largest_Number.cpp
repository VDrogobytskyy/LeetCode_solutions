#include <iostream>
#include <vector>
#include <queue>
#include <string>

class Solution {
    public:
        std::string kthLargestNumber(std::vector<std::string> &nums, int k) {
            std::priority_queue<std::string, std::vector<std::string>, Compare_string> prs_q;

            for(auto x : nums){
                prs_q.push(x);
            }

            for(int i = 0; i < k - 1; i++){
                prs_q.pop();
            }
            
            return prs_q.top();
        }

        struct Compare_string{
            bool operator()(const std::string &a, const std::string &b){
                if(a.size() != b.size()){
                    return a.size() < b.size();
                }
                return a < b;
            }
        };
};


int main(void){
    std::cout << std::endl;

    Solution s;

    std::vector<std::string> check_vec = {"3","6","7","10"};
    int check_k = 4;

    std::string result = s.kthLargestNumber(check_vec, check_k);
    std::cout << result << std::endl;

    std::cout << std::endl;
    return 0;
}