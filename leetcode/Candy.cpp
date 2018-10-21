#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
    	int total = 0;
        vector<int> current_candy(ratings.size() - 1, 1);
        for(int i = 0; i < ratings.size(); i++) {
        	if(ratings[i] < ratings[i+1]) {
        		current_candy[i+1] = current_candy[i] + 1;
        	}
        }

        for(int i = ratings.size() - 1; i > 0; i--) {
        	if(ratings[i] < ratings[i-1]) {
        		if(current_candy[i] + 1 > current_candy[i - 1]) {
        			current_candy[i - 1] = current_candy[i] + 1;
        		}
        	}
        }

        for(int i = 0; i < ratings.size(); i++) {
        	total += current_candy[i];
        }
        return total;
    }
};

int main() {
	Solution s;
	int arr[5] = {1, 3, 2, 2, 1};
	vector<int> v(arr, arr+5);
	cout << s.candy(v) << endl;
	return 0;
}