#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool check(vector<string> v, string s) {
		for(int i = 0; i < v.size(); i++) {
			vector<char> index;
			for(int j = 0; j < s.size(); j++) {
				if(v[i][j] != s[j]) {
					index.push_back(j);
				}
			}
			if(index.size() == 2) {
				int index1 = index[0];
				int index2 = index[1];
				if(v[i][index1] == s[index2]&&v[i][index2] == s[index1]) {
					return true;
				}
			}
		}
		return false;
	}


    int numSimilarGroups(vector<string>& A) {
        vector<vector<string>> result;
        for(int i = 0; i < A.size(); i++) {
        	int tag = 0;
        	vector<int> m;
        	for(int j = 0; j < result.size(); j++) {
        		if(check(result[j], A[i])) {
        			m.push_back(j);
        		}
        	}
        	if(m.size() == 0) {
        		vector<string> temp;
        		temp.push_back(A[i]);
        		result.push_back(temp);
        	} else if(m.size() == 1) {
        		result[m[0]].push_back(A[i]);
        	} else {
        		vector<string> v;
        		int tag = 0;
        		int k =0;
        		for(auto it = result.begin(); it != result.end(); it++) {
        			tag++;
        			if(tag == m[k]) {
        				k++;
        				v.insert(v.end(), result[tag].begin(), result[tag].end());
        				it = result.erase(it);
        			}
        		}
        		result.push_back(v);
        	}
        } 
        return result.size();
    }
};


int main() {
	string s[4] = {"tars", "rats", "arts", "star"};
	vector<string> v(s, s+4);
	Solution s1;
	cout << s1.numSimilarGroups(v) << endl;
	return 0;
}