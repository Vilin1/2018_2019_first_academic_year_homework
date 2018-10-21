#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        //build a gargh
        if(n == 1) {
        	return vector<int>(0);
        }
        vector<set<int> > s(n);
        queue<int> q;
        for(auto edge : edges) {
        	s[edge.first].insert(edge.second);
        	s[edge.second].insert(edge.first);
        }
        for(int i = 0; i < n; i++) {
        	if(s[i].size() == 1) {
        		q.push(i);
        	}
        }

        while(n > 2) {
        	int size = q.size();
        	n = n - size;
        	for(int i = 0; i < size; i++) {
        		int t = q.front();
        		q.pop();
        		for(auto a : s[t]) {
        			s[a].erase(t);
        			if(s[a].size() == 1) {
        				q.push(a);
        			}
        		}
			}
        }

        vector<int> r;
        while(!q.empty()) {
        	r.push_back(q.front());
        	q.pop();
        }
        return r;
    }
};

int main() {
	Solution s;
	return 0;
}