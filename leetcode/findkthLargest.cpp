#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	int r = nums.size() - 1, left = 0, right = r, l = left;
        
        while(1) {
        	l = left + 1;
        	r = right;
        	//cout << "b" << tag << l << r << endl;
        	while(l <= r) {
        		if(nums[l] <= nums[left]&&nums[r] > nums[left]) {
        			int temp = nums[l];
        			nums[l] = nums[r];
        			nums[r] = temp;
        			l++;
        			r--;
        		}
        		if(nums[r] <= nums[left]) {
        			r--;
        		}
        		if(nums[l] >= nums[left]) {
        			l++;
        		}
        		
        	}
        	int temp = nums[left];
        	nums[left] = nums[r];
        	nums[r] = temp;

        	int result = r;

        	if((k == result + 1)) {
        		return nums[result];
        	} else if(result < k - 1) {
        		left = result + 1;
        	} else {
        		right = result - 1;
        	}
        	//cout << "1" << tag << l << r << endl;
        }
        
    }
};

int main() {
	int arr[9] = {3,2,3,1,2,4,5,5,6};
	vector<int> v(arr, arr+9);
	Solution s;
	int r = s.findKthLargest(v, 4);
	cout << r << endl;
	return 0;
}