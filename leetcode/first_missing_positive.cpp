#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        //第一次遍历将数组重新调整顺序，将容器大小范围内的数调整好，
        //如nums[0]放1，nums[1]放2
        for(int i = 0; i < size; i++) {
        	while(nums[i] <= size&&nums[i] > 0&&nums[nums[i] - 1] != nums[i]) {
        		int temp = nums[nums[i] - 1];
        		nums[nums[i] - 1] = nums[i];
        		nums[i] = temp;
        	}
        }
        //第二次遍历找出第一个下标与其值不对应的，即nums[i]！=i+1的
        for(int i = 0; i < size; i++) {
        	if(nums[i] != i+1) {
        		return (i+1);
        	}
        }
        return (size+1);
    }
};

int main() {
	Solution s;
	int arr[5] = {3,4,-1,1};
	vector<int> v(arr, arr+4);
	cout << s.firstMissingPositive(v) << endl;
	return 0;
}