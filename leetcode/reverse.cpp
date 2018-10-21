#include <iostream>
#include <limits.h>
#include <math.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while(x != 0) {
        	int n = x%10;
        	x = x/10;
        	result = 10*result + n;
        	//cout << n << endl;
        }
        return (result < INT_MIN || result > INT_MAX) ? 0 : result;
    }
};

int main() {
	int n = -123;
	Solution s;
	cout << s.reverse(n) << endl;
	return 0;
}