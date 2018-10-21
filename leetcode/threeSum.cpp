#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	set<vector<int> > result;
    	int flag = 0;

    	if(nums.size() == 0) {
    		return vector<vector<int> >();
    	}
        for(int i = 0; i < nums.size() - 1; i++) {
        	for(int j = 0; j < nums.size() - i - 1; j++) {
        		if(nums[j] > nums[j+1]) {
        			int temp = nums[j];
        			nums[j] = nums[j+1];
        			nums[j+1] = temp;
        		}
        	}
        }

        if(nums[0] == nums[nums.size() - 1]) {
        	flag = 1;
        }

        int begin = 0, end = nums.size() - 1;
        for(int i = 0; i < nums.size(); i++) {
        	//cout << "ll" << endl;
        	begin = i + 1;
        	end = nums.size() - 1;

        	int target = 0 - nums[i];

        	while(begin < end) {
        		if(nums[begin] + nums[end] < target) {
        			begin++;
        		} else if(nums[begin] + nums[end] > target) {
        			end--;
        		} else {
        			vector<int> r;
        			r.push_back(nums[i]);
        			r.push_back(nums[begin]);
        			r.push_back(nums[end]);
        			result.insert(r);
        			begin++;
        			if(flag == 1) {
        				break;
        			}
        		}
        	}
        }
        vector<vector<int> > v_result(result.begin(), result.end());
        return v_result;
    }
};

int main() {
	int arr[6] = {-1,0,1,2,-1,-4};
	vector<int> t(arr, arr+6);
	Solution s;
	vector<vector<int> > r = s.threeSum(t);
	for(int i = 0; i < r.size(); i++) {
		for(int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}