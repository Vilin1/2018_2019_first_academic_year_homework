#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int threeSumClosest(int* nums, int numsSize, int target) {
	//对数组进行排序
	for(int i = 0; i < numsSize; i++) {
		for(int j = 0; j < numsSize - i - 1; j++) {
			if(nums[j] > nums[j+1]) {
				int temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		}
	}
	int tag = 9999;
	int flat = -1;
	//思路是先选定一个下标，通过另外两个数字的和确定最小的。从两边开始
    for(int i = 0 ; i < numsSize; i++) {
    	int begin = i + 1;
    	int end =  numsSize - 1;
    	int left = target - nums[i];
    	
    	while(begin < end) {
    		int sum = nums[begin] + nums[end];
    		if(sum < left) {
    			begin++;
    			if(abs(left - sum) < tag) {
    				tag = abs(left - sum);
    				flat = 0;
    			}
    		} else if(sum > left) {
    			end--;
    			if(abs(left - sum) < tag) {
    				tag = abs(left - sum);
    				flat = 1;
    			}
    		} else {
    			return (nums[i] + nums[begin] + nums[end]);
    		}
    	}
    }
    if(flat == 0) {
    	return target-tag;
    } else {
    	return target+tag;
    }
}

int main() {
	int nums[6] = {1,6,9,14,16,70};
	int n = threeSumClosest(nums,6,81);
	printf("%d\n", n);
	return 0;
}