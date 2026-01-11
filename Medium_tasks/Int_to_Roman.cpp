#include <iostream>
#include <string>
#include <vector>

class Solution {
    public:
        std::string intToRoman(int num) {
            std::string returned_value = "";
            const std::vector<std::pair<std::string, int>> romans_vals = {
                {"M", 1000},
                {"CM", 900},
                {"D", 500},
                {"CD", 400},
                {"C", 100},
                {"XC", 90},
                {"L", 50}, 
                {"XL", 40},
                {"X", 10}, 
                {"IX", 9},
                {"V", 5}, 
                {"IV", 4},
                {"I", 1}
            };

            while(num != 0){
                for(auto it = romans_vals.begin(); it != romans_vals.end();){
                    if((num - it->second) >= 0){
                        returned_value += it->first;
                        num -= it->second;
                        it = romans_vals.begin();
                    }else{
                        it++;
                    }
                }
            }
 
            return returned_value;
        }
};



int main(void){
    std::cout << std::endl;

    Solution s;

    std::string result = s.intToRoman(3749);
    std::cout << result << std::endl;

    std::cout << std::endl;
    return 0;
}