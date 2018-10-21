#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;


class Solution {
public:
    string intToRoman(int num) {
        int temp = num;
        string result;
        stack<int> s;
        map<int, string> m;
        m[1] = "I";
        m[5] = "V";
        m[10] = "X";
        m[50] = "L";
        m[100] = "C";
        m[500] = "D";
        m[1000] = "M";
        m[4] = "IV";
        m[9] = "IX";
        m[40] = "XL";
        m[90] = "XC";
        m[400] = "CD";
        m[900] = "CM";
        int count = 10;
        while(temp) {
        	temp /= 10;
        	int re = num%count;
        	s.push(re);
        	num = num - re;
        	count *= 10;
        }

        count /= 100;

        while(!s.empty()) {
        	int num = s.top();
        	//cout << num << endl;
        	s.pop();
        	int remain = num/count;
        	//cout << "r count " << remain << " " << count <<  endl; 
        	if(remain >= 1 && remain < 4) {
        		for(int i = 0; i < remain; i++) {
        			result.insert(result.size(),m[count]);
        		}
        	} else if(remain == 4||remain == 5||remain == 9) {
        		result.insert(result.size(),m[num]);
        	} else if(remain == 0) {

        	}else {
        		int n = 5*count;
        		result.insert(result.size(),m[n]);
        		remain = remain - 5;
        		for(int i = 0; i < remain; i++) {
        			result.insert(result.size(),m[count]);
        		}
        	}
        	count /= 10;
        }
        return result;
    }
};

int main() {
	Solution s;
	string r = s.intToRoman(1001);
	cout << r << endl;
	return 0;
}