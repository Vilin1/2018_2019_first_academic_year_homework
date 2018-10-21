#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
	void dfs(vector<vector<int>>& rooms, int index, vector<bool> &visited) {
		visited[index] = true;
		for(int i = 0; i < rooms[index].size(); i++) {
			if(!visited[rooms[index][i]]) {
				dfs(rooms, rooms[index][i], visited);
			}
		}
	}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    	vector<bool> visited(rooms.size(), false);
        dfs(rooms, 0, visited);
        for(int i = 0; i < rooms.size(); i++) {
        	if(!visited[i]) {
        		return false;
        	}
        }
        return true;
    }
};

int main() {
	int a1[1] = {1};
	int a2[1] = {2};
	int a3[1] = {3};
	vector<int> v1(a1,a1+1);
	vector<int> v2(a2,a2+1);
	vector<int> v3(a3,a3+1);
	vector<int> v4;
	vector<vector<int>> vv;
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);
	vv.push_back(v4);
	Solution s;
	cout << s.canVisitAllRooms(vv) << endl;

	return 0;
}