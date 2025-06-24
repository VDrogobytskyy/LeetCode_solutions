#include <iostream>
#include <vector>

class Solution {
    public:
        int minimumTotal(std::vector<std::vector<int>>& triangle) {
            for(int i=1;i<triangle.size();i++){
                for(int j=0;j<triangle[i].size();j++){
                    if(j==0){
                        triangle[i][j]=triangle[i][j]+triangle[i-1][j];
                    }else if(j==triangle[i].size()-1){

                        triangle[i][j]=triangle[i][j]+triangle[i-1][j-1];
                    }else{
                        triangle[i][j]=triangle[i][j]+std::min(triangle[i-1][j-1],triangle[i-1][j]);
                    }
                }
         }

        int sz=triangle.size()-1;
        int ans= *min_element(triangle[sz].begin(),triangle[sz].end());
        return ans;
    }
};



int main(void){
    std::cout << std::endl;

    Solution testing;
    std::vector<std::vector<int>> test_input = { {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3} };

    int result = testing.minimumTotal(test_input);

    std::cout << result << std::endl;

    std::cout << std::endl;
    return 0;
}