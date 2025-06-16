#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
    public:
        double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
            double returned_value;

            for(int i = 0; i < (int)nums2.size(); i++){
                nums1.push_back(nums2[i]);
            }
            std::sort(nums1.begin(), nums1.end());
            //auto it = std::unique(nums1.begin(), nums1.end());
            //nums1.erase(it, nums1.end());

            int len = nums1.size();
            if(len % 2 == 0){
                returned_value = (nums1[(len / 2) - 1] + nums1[(len / 2)]) / 2.0;
            }else{
                returned_value = nums1[((len + 1) / 2) - 1];
            }

            return returned_value;
        }
};


int main(void){
    std::cout << std::endl;

    Solution s;
    std::vector<int> check1 = {2, 2, 4, 4}, check2 = {2, 2, 2, 4, 4};
    double result = s.findMedianSortedArrays(check1, check2);

    std::cout << result << std::endl;

    std::cout << std::endl;
    return 0;
}