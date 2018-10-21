#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        int m = 0;
        int math = numRows + (numRows - 2);
        vector<vector<char> > v(numRows, vector<char>());
        if(numRows == 1||s.size() < numRows) {
        	return s;
        }
        for(int i = (numRows-1); i < s.size(); i = i+math) {
        	for(int j = 0; j < numRows; j++) {
        		if(j == 0) {
        			v[j].push_back(s[i]);
        		} else {
        			int l = i - j;
        			int r = i + j;
        			v[j].push_back(s[l]);
        			if(j != numRows - 1 &&r < s.size())
        				v[j].push_back(s[r]);
        		}
        	}
        	m = i;
        }

        if(m+numRows-1 < s.size()) {
        	for(int i = 0; i < numRows; i++) {
        		if(m+numRows-1+i < s.size()) {
        			v[numRows-1-i].push_back(s[m+numRows-1+i]);
        		}
        	}	
        }
        for(int i = numRows-1; i >= 0; i--) {
        	for(int j = 0; j < v[i].size(); j++) {
        		result.push_back(v[i][j]);
        	}
        }
        return result;
    }
};

int main() {
	Solution s;
	string n = s.convert("ABCDE", 4);
	cout << n << endl;
	return 0;
}