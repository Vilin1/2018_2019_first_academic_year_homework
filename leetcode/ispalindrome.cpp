#include <iostream>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
        	return false;
        }

        int new_int = 0, temp_x = x;
        while(x) {
        	new_int = new_int*10 + x%10;
        	x /= 10;
        }
        if(temp_x == new_int) {
        	return true;
        }
        return false;
    }
};

int main() {

	Solution s;
	int t = 121;
	cout << s.isPalindrome(t) << endl;
	return 0;
}