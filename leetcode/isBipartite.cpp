#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
	bool dfs(int source, vector<vector<int>>& graph, vector<int>& color, int current) {
		color[source] = current;
		for(int i = 0; i < graph[source].size(); i++) {
			if(color[graph[source][i]] == current) {
				return false;
			}
			if(color[graph[source][i]] == 0) {
				bool b = dfs(graph[source][i], graph, color, -current);
				if(!b) {
					return false;
				}
			}
		}
		return true;
	}

    bool isBipartite(vector<vector<int>>& graph) {
    	/*
        vector<int> color(graph.size(), 0);
        queue<int> q;
        for(int i = 0; i < graph.size(); i++) {
        	if(color[i] == 0) {
        		color[i] = -1;
        		q.push(i);
        		while(!q.empty()) {
        			int temp = q.front();
        			q.pop();
        			for(int j = 0; j < graph[temp].size(); j++) {
        				if(color[graph[temp][j]] == 0) {
        					color[graph[temp][j]] = 0 - color[temp];
        					q.push(graph[temp][j]);
        				}
        				if(color[temp] == color[graph[temp][j]]) {
        					return false;
        				}
        			}
        		}
        	}
        }
        return true;
        */

        vector<bool> visited(graph.size(), false);
        vector<int> color(graph.size(), 0);
        int c = 1;
        for(int i = 0; i < graph.size(); i++) {
        	if(color[i] == 0) {
        		bool b = dfs(i, graph, color, c);
        		if(b == false) {
        			return false;
        		}
        	}
        }
        return true;
    }
};


int main() {
	int arr1[2] = {1,3};
	int arr2[2] = {0,2};
	int arr3[2] = {1,3};
	int arr4[2] = {0,2};
	vector<int> v1(arr1, arr1+2);
	vector<int> v2(arr2, arr2+2);
	vector<int> v3(arr3, arr3+2);
	vector<int> v4(arr4, arr4+2);
	vector<vector<int> > vv;
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);
	vv.push_back(v4);
	Solution s;
	cout << s.isBipartite(vv) << endl;
	return 0;
}