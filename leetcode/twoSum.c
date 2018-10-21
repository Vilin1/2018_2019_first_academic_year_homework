#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target) {
    int begin = 0, end = numsSize-1;
    while(begin < end) {
    	int sum = nums[begin]+nums[end];
    	if(sum < target) {
    		begin++;
    	} else if(sum > target) {
    		end--;
    	} else {
    		break;
    	}
    }
    int *result = (int*)malloc(2*sizeof(int));
    result[0] = begin;
    result[1] = end;
    return result;
}

int main() {
	int *result = (int*)malloc(2*sizeof(int));
	int nums[3] = {3,2,4};
	result = twoSum(nums, 3, 6);
	for(int i = 0; i < 2; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}