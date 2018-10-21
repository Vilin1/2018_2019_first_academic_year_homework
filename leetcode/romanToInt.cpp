#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        int sum = 0;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
  		m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        for(int i = 0; i < s.size(); i++) {
        	int next = i+1;
        	if(next < s.size()) {
        		if(m[s[next]] > m[s[i]]) {
        			sum += (m[s[next]] - m[s[i]]);
        			i++;
        		} else {
        			sum +=  m[s[i]];
        		}
        	} else {
        		sum += m[s[i]];
        	}
        }
        return sum;
    }
};

int main() {
	Solution s;
	cout << s.romanToInt("IV") << endl;
	return 0;
}