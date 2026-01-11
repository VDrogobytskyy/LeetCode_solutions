#include <iostream>


class Solution {
public:
    int divide(int dividend, int divisor) {

        if (divisor == 0)
            throw std::runtime_error("division by zero");

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool is_negative = (dividend < 0) ^ (divisor < 0);

        long long dvd = std::llabs((long long)dividend);
        long long dvs = std::llabs((long long)divisor);

        long long quotient = 0;

        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            quotient += multiple;
        }

        if (is_negative)
            quotient = -quotient;

        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};


int main(void){
    std::cout << std::endl;

    Solution s;

    int result = s.divide(10, 3);

    std::cout << result << std::endl;

    std::cout << std::endl;
    return 0;
}