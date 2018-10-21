#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.size() == 0||(matrix.size() != 0&&matrix[0].size() == 0)) {
        	return false;
        }
        for(int i = 0; i < matrix.size(); i++) {
        	if(matrix[i][matrix[0].size() - 1] < target||matrix[i][0] > target) {
        		continue;
        	}
        	if(binary_search(matrix[i],target)) {
        		return true;
        	}
        }
        return false;
    }
    bool binary_search(vector<int> m, int target) {
    	int begin = 0, end = m.size() - 1, middle = (begin + end)/2;
    	while(begin <= end) {
    		middle = (begin + end)/2;
    		if(target == m[middle]) {
    			return true;
    		} else if(target < m[middle]) {
    			end = middle -1;
    		} else {
    			begin = middle + 1;
    		}
    	}
    	return false;
    }
};


int main() {
	Solution s;
	int a1[5] = {1,4,7,11,15};
	int a2[5] = {2,5,8,12,19};
	int a3[5] = {3,6,9,16,22};
	int a4[5] = {10,13,14,17,24};
	int a5[5] = {18,21,23,26,30};
	vector<int> v1(a1,a1+5);
	vector<int> v2(a2,a2+5);
	vector<int> v3(a3,a3+5);
	vector<int> v4(a4,a4+5);
	vector<int> v5(a5,a5+5);
	vector<vector<int> > vv;
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);
	vv.push_back(v4);
	vv.push_back(v5);
	bool a = s.searchMatrix(vv, 5);
	cout << a << endl;
	return 0;
}