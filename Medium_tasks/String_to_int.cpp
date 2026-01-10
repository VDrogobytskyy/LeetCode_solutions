#include <iostream>
#include <string>
#include <cstdlib>

class Solution{
    public:
        int myAtoi(std::string s) {
            int starting_pos = 0;
            int end_of_string = s.length();
            bool is_number_negative = false;
            int returned_value = 0;

            while(starting_pos < end_of_string && isspace(s[starting_pos])){
                starting_pos++;
            }


            if(starting_pos == end_of_string){
                return 0;
            }

            if(s[starting_pos] == '-'){
                is_number_negative = true;
                starting_pos++;

            }else if(s[starting_pos] == '+'){
                
                starting_pos++;

            }else if(!isdigit(s[starting_pos])){
                return 0;
            }

            if(starting_pos == end_of_string){
                return 0;
            }

            while(starting_pos < end_of_string && s[starting_pos] == '0'){
                starting_pos++;
            }
            if(starting_pos == end_of_string){
                return 0;
            }

            while(starting_pos < end_of_string && isdigit(s[starting_pos])){
                int extracted_digit = s[starting_pos] - '0';
                

                if(returned_value > ((INT_MAX - extracted_digit) / 10)){
                    if(is_number_negative){
                        return INT_MIN;
                    }else{
                        return INT_MAX;
                    }
                }
                returned_value = returned_value * 10 + extracted_digit;


                starting_pos++;
            }
            if(is_number_negative){
                returned_value = -returned_value;
            }

            return returned_value;
        }

};

int main(void){
    std::cout << std::endl;

    Solution s;
    int my_answer = s.myAtoi("-91283472332");
    std::cout << my_answer << std::endl;

    std::cout << std::endl;
    return 0;
}