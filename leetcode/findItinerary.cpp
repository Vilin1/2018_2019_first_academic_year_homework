#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;


class Solution {
public:
	void DFS(string source, map<string, multiset<string> > &graph, vector<string> &result) {
		while(graph[source].size()) {
			string temp = *graph[source].begin();
			graph[source].erase(graph[source].begin());
			DFS(temp, graph, result);
		}
		result.push_back(source);
	}

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, multiset<string> > graph;
        vector<string> result;
        for(auto a : tickets) {
        	graph[a.first].insert(a.second);
        }
        string start = "JFK";
        DFS(start, graph, result);
        vector<string> r(result.rbegin(), result.rend());
        return r;
    }
};


int main() {
	Solution s;
	vector<pair<string, string>> t;
	t.push_back(make_pair("MUC", "LHR"));
	t.push_back(make_pair("JFK", "MUC"));
	t.push_back(make_pair("SFO", "SJC"));
	t.push_back(make_pair("LHR", "SFO"));
	vector<string> v = s.findItinerary(t);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}