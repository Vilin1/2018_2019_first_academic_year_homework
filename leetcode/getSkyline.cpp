#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<pair<int, int>> merge(vector<pair<int, int>> left, vector<pair<int, int>> right) {
		int l_index = 0, r_index = 0;
		int l_height = 0, r_height = 0;
		vector<pair<int, int>> result;
		while(l_index < left.size()&&r_index < right.size()) {
			int max = 0;
			//case l_index < r_index, get l_index
			if(left[l_index].first < right[r_index].first) {
				if(left[l_index].second > r_height) {
					max = left[l_index].second;
				} else {
					max = r_height;
				}
				if(result.empty()||result.back().second != max) {
					result.push_back(make_pair(left[l_index].first, max));
				}
				l_height = left[l_index].second;
				l_index++;
			}
			//case l_index > r_index, get r_index
			else if(left[l_index].first > right[r_index].first) {
				if(right[r_index].second > l_height) {
					max = right[r_index].second;
				} else {
					max = l_height;
				}
				if(result.empty()||result.back().second != max) {
					result.push_back(make_pair(right[r_index].first, max));
				}
				r_height = right[r_index].second;
				r_index++;
			}
			//case l_index == r_index
			else {
				if(right[r_index].second > left[l_index].second) {
					max = right[r_index].second;
				} else {
					max = left[l_index].second;
				}
				if(result.empty()||result.back().second != max) {
					result.push_back(make_pair(right[r_index].first, max));
				}
				r_height = right[r_index].second;
				l_height = left[l_index].second;
				r_index++;
				l_index++;
			}
		}

		//some pair left, add directly
		for(int i = l_index; i < left.size(); i++) {
			if(result.empty()||result.back().second != left[i].second) {
				result.push_back(make_pair(left[i].first, left[i].second));
			}
		}
		for(int i = r_index; i < right.size(); i++) {
			if(result.empty()||result.back().second != right[i].second) {
				result.push_back(make_pair(right[i].first, right[i].second));
			}
		}return result;

	}

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    	vector<pair<int, int>> temp;
    	if(buildings.empty()) {
    		return vector<pair<int,int>>();
    	}
        if(buildings.size() == 1) {
        	temp.push_back(make_pair(buildings[0][0], buildings[0][2]));
        	temp.push_back(make_pair(buildings[0][1], 0));
        	return temp;
        }
        int middle = buildings.size()/2;
        vector<vector<int>> left_buildings(buildings.begin(), buildings.begin()+middle);
        vector<vector<int>> right_buildings(buildings.begin()+middle, buildings.end());
        vector<pair<int,int>> left = getSkyline(left_buildings);
        vector<pair<int,int>> right = getSkyline(right_buildings);
        return merge(left, right);

    }
};

int main() {

	return 0;
}