#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class Solution {
    public:
        std::string longestCommonPrefix(std::vector<std::string> &strs) {

            if(strs.size() == 0) return "";
            if(strs.size() == 1) return strs[0];

            std::string returned_value;

            for(int i = 0; i < (int)strs[0].size(); i++){
                for(int j = 0; j < (int)strs.size(); j++){
                    if(i >= (int)strs[j].size() || strs[j][i] != strs[0][i]){    
                        return returned_value;
                    }
                    
                }
                returned_value += strs[0][i];
            }

            return returned_value;
        }
};

int main(void){
    std::cout << std::endl;

    Solution s1;

    std::vector<std::string> check = {"flower", "flow", "flight"};
    std::string result = s1.longestCommonPrefix(check);

    std::cout << "Result is: " << result << std::endl;


    std::cout << std::endl;
    return 0;
}