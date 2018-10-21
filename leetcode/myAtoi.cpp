#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
	int getIndex(string str) {
		int index = -1;
		for(int i = 0; i < str.size(); i++) {
			if(str[i] != ' ') {
				index = i;
				break;
			}
		}
		return index;
	}
	int getLastIndex(int index, string str) {
		int lastIndex = str.size();
        int tag = 0;
		for(int i = index; i < str.size(); i++) {
			if((str[i] < '0'||str[i] > '9')&&!(str[i] == '-'||str[i] == '+')) {
				lastIndex = i;
				break;
			}
		}
        //cout << "lastIndex" << lastIndex << endl;
		return lastIndex;
	}
    int myAtoi(string str) {
        int index = getIndex(str);
        //cout << "index" << index << endl;
        int flag = 0;
        string target;
        if(index == -1||str[index] != '-'&&str[index] != '+'&&(str[index] < '0'||str[index] > '9')) {
        	return 0;
        } else {
        	int lastIndex = getLastIndex(index, str);
        	
        	if(str[index] == '-') {
        		flag = -1;
        		target = str.substr(index+1, lastIndex-index-1);
                
        	} else if(str[index] == '+') {
        		flag = 1;
        		target = str.substr(index+1, lastIndex-index-1);
        	} else {
        		target = str.substr(index, lastIndex-index);
        	}
            int tag = 0;
            for(int i = 0; i < target.size(); i++) {
                if(target[i] < '0'||target[i] > '9') {
                    lastIndex = i;
                    break;
                }
            }
            target = target.substr(0, lastIndex);
            //cout << target << endl;
        }

        long long sum = 0;
        for(int i = 0; i < target.size(); i++) {
            if(target[i] < '0'||target[i] > '9') {
                return 0;
            }
            sum = sum*10 + (target[i] - '0');
            if(sum > INT_MAX) {
                break;
            }
        }
        //cout << "flag" << flag << endl;
        if(flag == -1) {
        	sum = 0-sum;
        }
      	
        //cout << sum << endl;
        if(sum < INT_MIN) {
            return INT_MIN;
        } else if(sum > INT_MAX) {
            return INT_MAX;
        }else {
            return sum;
        }
    }
};

int main() {
	string str = "-1-";
    Solution s;
	int n = s.myAtoi(str);
	cout << n << endl;
	return 0;
}