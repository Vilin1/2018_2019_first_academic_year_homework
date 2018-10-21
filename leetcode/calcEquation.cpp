#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;


class Solution {
public:
	double dfs(string source, string dest, set<string> &visited, map<string, vector<pair<string, double>>> &graph) {
		if(source == dest) {
			return 1.0;
		}
		visited.insert(source);
		for(int i = 0; i < graph[source].size(); i++) {
			if(visited.find(graph[source][i].first) == visited.end()) {
				double num = dfs(graph[source][i].first, dest, visited, graph);
				if(num != -1.0) {
					return (num*graph[source][i].second);
				}
			}
		}
		return -1.0;
	}

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, vector<pair<string, double>>> graph;
        for(int i = 0; i < equations.size(); i++) {
        	graph[equations[i].first].push_back(make_pair(equations[i].second, values[i]));
        	graph[equations[i].second].push_back(make_pair(equations[i].first, 1/values[i]));
        }
        
       /* for(auto a : graph) {
        	cout << a.first << endl;
        }
        */
        vector<double> result;
        for(int i = 0; i < queries.size(); i++) {
        	if(graph.find(queries[i].first) == graph.end()) {
        		result.push_back(-1.0);
        		continue;
        	}
        	set<string> visited;
        	string source = queries[i].first;
        	string dest = queries[i].second;
        	double num = dfs(source, dest, visited, graph);
        	result.push_back(num);
        }
        return result;
    }
};

int main() {
	
	vector<pair<string, string>> equations;
	equations.push_back(make_pair("a", "b"));
	equations.push_back(make_pair("b", "c"));
	vector<double> v;
	v.push_back(2.0);
	v.push_back(3.0);
	vector<pair<string, string>> query;
	query.push_back(make_pair("a", "c"));
	query.push_back(make_pair("b", "a"));
	query.push_back(make_pair("a", "e"));
	query.push_back(make_pair("a", "a"));
	query.push_back(make_pair("x", "x"));
	Solution s;

	vector<double> r = s.calcEquation(equations,v,query);
	for(int i = 0; i < r.size(); i++) {
		cout << r[i] << endl;
	}
	
	return 0;
}