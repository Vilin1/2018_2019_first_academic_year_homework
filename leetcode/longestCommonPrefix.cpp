#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.size() == 0) {
    		return "";
    	}
    	if(strs.size() == 1) {
    		return strs[0];
    	}

        int index = strs[0].size();
        for(int i =0; i < strs[0].size(); i++) {
        	int tag = 0;
        	for(int j = 1; j < strs.size(); j++) {
        		if(i < strs[j].size())
        			if(strs[0][i] != strs[j][i]) {
        				index = i;
        				tag = 1;
        				break;

        			}
        		}
        	if(tag == 1) {
        		break;
        	}
        }
        //cout << index << endl;
        if(index == 0) {
        	return "";
        }
        string result = strs[0].substr(0, index);
        return result;
    }
};

int main() {
	Solution s;
	vector<string> t;
	t.push_back("c");
	t.push_back("c");
	string r = s.longestCommonPrefix(t);
	cout << r << endl;
	return 0;
}