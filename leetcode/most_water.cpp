#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
    	//max is the largest value at this time
        int max = 0;
        int size = height.size();
        int i = 0, j = size - 1;
        int temp = 0;
        //loop to find the max value
        while(i < j) {
        	//在左边的下一条边小与前一条边的时候继续遍历
        	if(height[i] < height[j]) {
        		temp = height[i]*(j-i);
        		i++;
        	} else {//在左边的下一条边大与前一条边的时候换一个方向遍历
        		temp = height[j]*(j-i);
        		j--;
        	}
        	if(max < temp) {//找最大的值max
        		max = temp;
        	}
        }
        return max;
    }
};

int main() {
	Solution s;
	int a[9] = {1,8,6,2,5,4,8,3,7};
	vector<int> m(a, a+9);
	cout << s.maxArea(m) << endl;
	return 0;
}