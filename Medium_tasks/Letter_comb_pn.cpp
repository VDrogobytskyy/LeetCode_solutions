#include <iostream>
#include <vector>
#include <string>
#include <map>


class Solution {
    public:
        std::vector<std::string> letterCombinations(std::string digits) {

            if(digits.empty()) return {};
            std::vector<std::string> returned_value;
            creating_result(digits, 0, "", returned_value);
            return returned_value;
        }
    private:
        std::map<char, std::string> values = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        void creating_result(const std::string digits, int position, std::string current, std::vector<std::string> &returned_value){

            if(position == (int)digits.size()){
                returned_value.push_back(current);
                return;
            }
            for(char x : values[digits[position]]){
                creating_result(digits, position + 1, current + x, returned_value);
            }
        }
};


int main(void){
    std::cout << std::endl;

    Solution s;

    std::string check_str = "23";
    std::vector<std::string> res = s.letterCombinations(check_str);

    for(auto x : res){
        std::cout << x << std::endl;
    }

    std::cout << std::endl;
    return 0;
}