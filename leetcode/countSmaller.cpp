#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
    	vector<int> count(nums.size(), 0);
        vector<int> new_nums;
        int left = 0, right = 0;
        for(int i = nums.size() - 1; i >= 0; i--) {
        	left = 0;
        	right = new_nums.size();
        	while(left < right) {
        		int middle = (left + right)/2;
        		if(new_nums[middle] >= nums[i]) {
        			right = middle;
        		}
        		if(new_nums[middle] < nums[i]) {
        			left = middle + 1;
        		}
        	}
        	count[i] = right;
        	new_nums.insert(new_nums.begin()+right, nums[i]);
        }
        return count;
    }
};


int main() {
	Solution s;
	int arr[4] = {5,2,6,1};
	vector<int> v(arr, arr+4);
	vector<int> m = s.countSmaller(v);
	for(int i = 0; i < m.size(); i++) {
		cout << m[i] << endl;
	}
	return 0;
}