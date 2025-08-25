#include <iostream>
#include <string>


class Solution {
    public:
        bool isPalindrome(int x) {
            std::string s1 = std::to_string(x);
            std::string s2 = std::string(s1.rbegin(), s1.rend());
            
            return s1 == s2;
        }
};

int main(void){
    std::cout << std::endl;

    Solution s1;
    bool result = s1.isPalindrome(123);

    std::cout << std::boolalpha;
    std::cout << "result for 123 is: " << result << std::endl;

    std::cout << std::endl;

    return 0;
}