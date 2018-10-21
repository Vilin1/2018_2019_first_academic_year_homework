#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int medianSize = totalSize/2;
    int a1 = 0, a2 = 0;
    double result = 0;
    int t = 1;
    //当第一个数组为空的时候，再分别讨论奇偶
    if(nums1Size == 0) {
    	if(totalSize%2 == 0) {
    		int tag1,tag2;
    		for(int i = 0; i <= medianSize; i++) {
    			if(i == medianSize -1) {
    				tag1 = nums2[i];
    			}
    			if(i == medianSize) {
    				tag2 = nums2[i];
    			}
    		}
    		return (double)(tag1+tag2)/2;
    	} else {
    		int tag1,tag2;
    		for(int i = 0; i <= medianSize; i++) {
    			if(i == medianSize) {
    				tag1 = nums2[i];
    			}
    		}
    		return tag1;
    	}
    }
    //当第二个数组为空的时候，再分别讨论奇偶
    if(nums2Size == 0) {
    	if(totalSize%2 == 0) {
    		int tag1,tag2;
    		for(int i = 0; i <= medianSize; i++) {
    			if(i == medianSize -1) {
    				tag1 = nums1[i];
    			}
    			if(i == medianSize) {
    				tag2 = nums1[i];
    			}
    		}
    		return (double)(tag1+tag2)/2;
    	} else {
    		int tag1,tag2;
    		for(int i = 0; i <= medianSize; i++) {
    			if(i == medianSize) {
    				tag1 = nums1[i];
    			}
    		}
    		return tag1;
    	}
    }
    if(totalSize%2 == 0) {
    	int tag1 = 0, tag2 = 0;
    	for(int i = 0; i <= medianSize; i++) {	
    		if((nums1[a1] <= nums2[a2])&&(a1 < nums1Size)||a2 == nums2Size) {
  				if(i == medianSize - 1) {
  					tag1 = nums1[a1];
  				}
  				if(i == medianSize) {
  					tag2 = nums1[a1];
  				}
  				a1++;
    		} else{
    			if(i == medianSize - 1) {
    				tag1 = nums2[a2];
    			}
    			if(i == medianSize) {
    				tag2 = nums2[a2];
    			}
    			a2++;
    		}

    	}
    	//printf("%d\n", tag1);
    	return (double)(tag1+tag2)/2;
    } else {
    	int tag1 = 0;
    	for(int i = 0; i <= medianSize; i++){
			if((nums1[a1] <= nums2[a2])&&(a1 < nums1Size)||a2 == nums2Size) {
				if(i == medianSize ) {
					tag1 = nums1[a1];
				}
				a1++;
			} else {
				if(i == medianSize) {
					tag1 = nums2[a2];
				}
				a2++;
			}
		}
		return tag1;
    }
}


int main() {
	int num1[1] = {10001};
	int num2[1] = {10000};
	double r = findMedianSortedArrays(num1,1,num2,1);
	printf("%f\n", r);
	return 0;
}