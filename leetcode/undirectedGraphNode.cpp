#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

struct UndirectedGraphNode {
    int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if(node == NULL) {
        	return NULL;
        }
        queue<UndirectedGraphNode *> q;
        set<UndirectedGraphNode *> s;
        UndirectedGraphNode *newGraph = new UndirectedGraphNode(node->label);
        UndirectedGraphNode *resultGraph = newGraph;
        //通过旧的点找到新图的点，因为需要新图的连接
        map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        
        q.push(node);
        s.insert(node);
        m[node] = newGraph;
        while(!q.empty()) {
        	//一层的顶点
        	int size = q.size();
        	for(int i = 0; i < size; i++) {
        		UndirectedGraphNode *temp = q.front();
        		UndirectedGraphNode *end = m[temp];
        		q.pop();
        		for(int j = 0; j < temp->neighbors.size(); j++) {
        			if(s.find(temp->neighbors[j]) == s.end()) {
        				s.insert(temp->neighbors[j]);
        				q.push(temp->neighbors[j]);
        			}
        			if(m.find(temp->neighbors[j]) == m.end()) {
        				UndirectedGraphNode* copiedNeighbor = new UndirectedGraphNode(temp->neighbors[j]->label);
                        m[temp->neighbors[j]] = copiedNeighbor;
        			}
        			//将一个图接起来
        			end->neighbors.push_back(m[temp->neighbors[j]]);
        		}
        		
        	}
        	
        }
        return resultGraph;
    }
};

int main() {

	return 0;
}