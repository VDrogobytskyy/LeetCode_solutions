#include <iostream>
#include <string>


class Solution {
    public:
        int romanToInt(std::string s) {
            int str_len = s.length();
            int returned_value = 0;
            for(int i = 0; i < str_len; i++){
                if(convert_num(s[i]) < convert_num(s[i + 1])){
                    returned_value -= convert_num(s[i]);
                }else{
                    returned_value += convert_num(s[i]);
                }
            }
            return returned_value;
            
        }

    private:
        int convert_num(char c){
            switch (c){
                case 'M':
                    return 1000;
                case 'D':
                    return 500;
                case 'C':
                    return 100;
                case 'L':
                    return 50;
                case 'X':
                    return 10;
                case 'V':
                    return 5;
                case 'I':
                    return 1;
                default:
                    return 0;
            
            return 0;
            }
        }
};

int main(void){
    std::cout << std::endl;

    Solution s;

    std::string text_str = "MCMXCIV";
    int result = s.romanToInt(text_str);
    std::cout << result << std::endl;

    std::cout << std::endl;
    return 0;
}