#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	int max = 0;
    	stack<int> s;
    	for(int i = 0; i < heights.size(); i++) {
    		while((!s.empty())&&heights[s.top()] > heights[i]) {
    			int top = s.top();
    			s.pop();
    			int temp = 0;
    			if(s.empty()) {
    				temp = i*heights[top];
    			} else {
    				temp = heights[top]*(i-s.top()-1);
    			}
    			if(temp > max) {
    				max = temp;
    			}
    		}
    		s.push(i);
    	}

    	while(!s.empty()) {
    		int top = s.top();
    		int h = heights[top];
    		s.pop();
    		int sum = 0;
    		if(s.empty()) {
    			sum = heights.size()*h;
    		} else {
    			sum = h*(heights.size() - 1 - s.top());
    		}
    		if(sum > max) {
    			max = sum;
    		}
    	}
    	return max;
    }
};

int main() {
	int arr[6] = {2,1,5,6,2,3};
	vector<int> v(arr, arr+6);
	Solution s;
	int c = s.largestRectangleArea(v);
	cout << c << endl;
	return 0;
}