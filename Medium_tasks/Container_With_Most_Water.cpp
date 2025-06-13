#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
    public:
        int maxArea(std::vector<int> &height) {
            int max_arr = 0;
            int arr_len = (int)height.size();
            int *start_ptr = &height[0], *finish_ptr = &height[arr_len - 1];

            int min_of_both_side = std::min(*start_ptr, *finish_ptr);
            int dist = finish_ptr - start_ptr;

            max_arr = arr_calc(min_of_both_side, dist);

            do{

                if(*start_ptr < *finish_ptr){
                    start_ptr++;
                    min_of_both_side = std::min(*start_ptr, *finish_ptr);
                    dist = finish_ptr - start_ptr;
                    int temp_arr = arr_calc(min_of_both_side, dist);

                    if(temp_arr > max_arr){
                        max_arr = temp_arr;
                    }
                }else{
                    finish_ptr--;
                    min_of_both_side = std::min(*start_ptr, *finish_ptr);
                    dist = finish_ptr - start_ptr;
                    int temp_arr = arr_calc(min_of_both_side, dist);
                    if(temp_arr > max_arr){
                        max_arr = temp_arr;
                    }
                }

            }while(start_ptr != finish_ptr);


            return max_arr;
        }

        int arr_calc(int less_height, int dist){
            return less_height * dist;
        }

};


int main(void){
    std::cout << std::endl;

    Solution s;

    std::vector<int> check = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };

    int result = s.maxArea(check);

    std::cout << result << std::endl;

    std::cout << std::endl;
    return 0;
}