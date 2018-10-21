#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0, count = 0;
        if(nums.size() == 1) {
        	return 0;
        }
        if(nums.size() != 0) {
        	if(nums[0] + 0 >= nums.size() - 1) {
        		return 1;
        	}
        }
        int max = 0;
        for(int i = 0; i < nums.size() - 1;) {
        	//cout << i << endl;
        	result = nums[i] + i;
        	int tag = 0;
        	int index = i;
        	for(int j = i + 1; j <= nums[i] + i ; j++) {
        		if((nums[j] + j > max)) {
        			max = nums[j] + j;
        			index = j;
        			tag =1;
        		}
        	}

        	//cout << max << endl;
        	if(tag == 1) {
        		count++;
        		result = max;
        		i = index;
        	} else {
        		i++;
        	}
        	//cout << result << endl;
        	if(result >= nums.size() - 1) {
        		break;
        	}
        }
        return count + 1;
    }
};

int main() {
	int arr[5] = {1,2,1,1,1};
	vector<int> v(arr, arr+5);
	Solution s;
	cout << s.jump(v) << endl;
	return 0;
}