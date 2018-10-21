#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> in(numCourses,0);
        queue<int> empty;
        vector<vector<int> > temp(numCourses, vector<int>(0));
        //建立图，vector的二维数组
        for(auto a : prerequisites) {
        	temp[a.second].push_back(a.first);
        	in[a.first]++;
        }
        
        //将入度为0的点存进队列里面
        for(int i = 0; i < numCourses; i++) {
        	if(in[i] == 0) {
        		empty.push(i);
        	} 
        }
        //入度为0的点作为开始的点，检查是否有环
        while(!empty.empty()) {
        	int frist_point = empty.front();
        	empty.pop();
        	for(auto a : temp[frist_point]) {
        		in[a]--;
                if(in[a] == 0) {
                    empty.push(a);
                }
        	}
        }
        for(int i = 0; i < numCourses; i++) {
        	if(in[i] != 0) {
        		return false;
        	}
        }
        return true;
    }
};

int main() {
	Solution
	return 0;
}