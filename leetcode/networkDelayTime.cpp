#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <limits.h>
using namespace std;


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        /*build a graph
		* the key of map is the source
		* the first element of vector is the target
		* the second is the distance
        */
        int count = 0;
        map<int, vector<vector<int> > > graph;
        for(auto a : times) {
        	vector<int> temp;
        	temp.push_back(a[1]);
        	temp.push_back(a[2]);
        	graph[a[0]].push_back(temp);
        }

        //the min distance
        vector<int> dist(N+1, INT_MAX);
        vector<bool> visited(N+1, false);
        dist[K] = 0;

        queue<int> q;
        set<int> s;
        q.push(K);
        s.insert(K);

        while(!q.empty()) {
        	int index = q.front();
        	s.erase(index);
        	visited[index] = true;
        	//cout << index << endl;
        	q.pop();
        	for(int i = 0; i < graph[index].size(); i++) {
        		if(dist[graph[index][i][0]] > dist[index] + graph[index][i][1]) {
        			dist[graph[index][i][0]] = dist[index] + graph[index][i][1];
        			if(s.find(graph[index][i][0]) == s.end())
        				q.push(graph[index][i][0]);
        		}
        			
        	}
        }

        int result = -1;
        for(int i = 1; i < N+1; i++) {
        	if(dist[i] == INT_MAX) {
        		return -1;
        	}
        	if(dist[i] > result) {
        		result = dist[i];
        	}
        }
        return result;
    }
};

/*
        //array to tag weather the element is visited
        vector<int> array_queue(N+1, INT_MAX);
        vector<bool> bool_(N+1, false);
        array_queue[K] = 0;

        int index = 0;
        while(count < N) {
        	int min = INT_MAX;
        	for(int i = 1; i < array_queue.size(); i++) {
        		if(bool_[i] == false) {
        			if(array_queue[i] < min) {
        				min = array_queue[i];
        				index = i;
        			}
        		}
        	}

        	bool_[index] = true;
        	count++;
        	//cout << "index " << index << endl;

        	//find the distance
        	for(int i = 0; i < graph[index].size(); i++) {
        		//cout << "graph[index][i][0] " << graph[index][i][0] << endl;
        		if(dist[graph[index][i][0]] > dist[index] + graph[index][i][1]) {
        			dist[graph[index][i][0]] = dist[index] + graph[index][i][1];
        			array_queue[graph[index][i][0]] = dist[graph[index][i][0]];
        		}
        	}
   	}

   		int result = -1;
        for(int i = 1; i < N+1; i++) {
        	if(dist[i] == INT_MAX) {
        		return -1;
        	}
        	if(dist[i] > result) {
        		result = dist[i];
        	}
        }
        return result;
        */

int main() {
	int arr1[3] = {1,2,1};
	int arr2[3] = {2,1,3};
	//int arr3[3] = {2,3,1};
	//int arr4[3] = {2,4,2};
	//int arr5[3] = {2,5,3};
	//int arr6[3] = {3,5,4};
	vector<int> t1(arr1, arr1+3);
	vector<int> t2(arr2, arr2+3);
	//vector<int> t3(arr3, arr3+3);
	//vector<int> t4(arr4, arr4+3);
	//vector<int> t5(arr5, arr5+3);
	//vector<int> t6(arr6, arr6+3);

	vector<vector<int>> vv;
	vv.push_back(t1);
	vv.push_back(t2);
	//vv.push_back(t3);
	//vv.push_back(t4);
	//vv.push_back(t5);
	//vv.push_back(t6);

	Solution s;
	cout << s.networkDelayTime(vv, 2, 2) << endl;

	return 0;
}