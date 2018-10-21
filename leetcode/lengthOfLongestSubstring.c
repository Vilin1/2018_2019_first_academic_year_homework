#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int *count = (int*)malloc(256*sizeof(int));
    memset(count,0,256*sizeof(int));
    int *last_seen =  (int*)malloc(256*sizeof(int));
    memset(last_seen,0,256*sizeof(int));
    int max = 0;
    int tag = 0;
    for(int i = 0; i < len; i++) {
    	count[s[i]]++;
    	if(count[s[i]] > 1) {
    		if(max < tag) {
    			max = tag;
    		}
    		tag = 0;
    		memset(count,0,256*sizeof(int));
    		i = last_seen[s[i]];
    		memset(last_seen,0,256*sizeof(int));
    		continue;
    	} else {
    		tag++;
    		last_seen[s[i]] = i;
    		if(max < tag) {
    			max = tag;
    		}
    	}
    }
    free(count);
    free(last_seen);
    return max;
}

int main() {
	int len = lengthOfLongestSubstring("pwwkew");
	printf("%d\n", len);
	return 0;
}