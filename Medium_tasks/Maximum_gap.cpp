#include <iostream>
#include <vector>
#include <limits>


class Solution {
public:
    int maximumGap(std::vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int minVal = nums[0], maxVal = nums[0];
        for (int x : nums) {
            minVal = std::min(minVal, x);
            maxVal = std::max(maxVal, x);
        }

        if (minVal == maxVal) return 0;

        int bucketSize = std::max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        std::vector<int> bucketMin(bucketCount, INT_MAX);
        std::vector<int> bucketMax(bucketCount, INT_MIN);
        std::vector<bool> used(bucketCount, false);

        for (int x : nums) {
            int idx = (x - minVal) / bucketSize;
            bucketMin[idx] = std::min(bucketMin[idx], x);
            bucketMax[idx] = std::max(bucketMax[idx], x);
            used[idx] = true;
        }

        int maxGap = 0;
        int prevMax = minVal;

        for (int i = 0; i < bucketCount; ++i) {
            if (!used[i]) continue;

            maxGap = std::max(maxGap, bucketMin[i] - prevMax);
            prevMax = bucketMax[i];
        }

        return maxGap;
    }
};

int main(void){
    std::cout << std::endl;

    Solution s;
    std::vector<int> test_vec = {3,6,9,1};

    int result = s.maximumGap(test_vec);

    std::cout << result << std::endl;

    std::cout << std::endl;
    return 0;
}