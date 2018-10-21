#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //every two merge
        if(lists.empty()) {
            return NULL;
        }
        return merge(lists, 0, lists.size()-1);
    }


    ListNode* merge_two(ListNode *l1, ListNode *l2) {
    	if(l1 == NULL&&l2 == NULL) {
    		return NULL;
    	}
    	if(l1 == NULL) {
    		return l2;
    	}
    	if(l2 == NULL) {
    		return l1;
    	}
    	if(l1->val < l2->val) {
    		l1->next = merge_two(l1->next, l2);
    		return l1;
    	} else {
    		l2->next = merge_two(l2->next, l1);
    		return l2;
    	}
    }

    ListNode* merge(vector<ListNode*>& lists, int begin, int end) {
        //condition to end
        if(begin == end) {
            return lists[begin];
        }

        int middle = (begin + end)/2;

        ListNode *l1 = merge(lists, begin, middle);
        ListNode *l2 = merge(lists, middle+1, end);

        return merge_two(l1, l2);
    }
};


int main() {
	Solution s;
	
	return 0;
}